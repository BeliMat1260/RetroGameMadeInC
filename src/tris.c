#include "tris.h"
#include "console.h"
#include "punteggio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const int RIGHE[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

static char a(const char b[3][3], int i) {
    return b[i / 3][i % 3];
}

char tris_vincitore(const char b[3][3]) {
    for (int r = 0; r < 8; r++) {
        char primo = a(b, RIGHE[r][0]);
        if (primo != ' ' && primo == a(b, RIGHE[r][1]) && primo == a(b, RIGHE[r][2])) {
            return primo;
        }
    }
    return ' ';
}

int tris_pieno(const char b[3][3]) {
    for (int i = 0; i < 9; i++) {
        if (a(b, i) == ' ') return 0;
    }
    return 1;
}

/* Cerca una mossa che completa una riga del simbolo indicato. Ritorna 0-8 oppure -1. */
static int mossa_che_chiude(const char b[3][3], char simbolo) {
    for (int i = 0; i < 9; i++) {
        if (a(b, i) != ' ') continue;
        char copia[3][3];
        memcpy(copia, b, sizeof copia);
        copia[i / 3][i % 3] = simbolo;
        if (tris_vincitore(copia) == simbolo) return i;
    }
    return -1;
}

/* 1 se vince O, -1 se vince X, 0 pareggio o partita aperta valutata a fondo. */
static int minimax(char b[3][3], int turno_o) {
    char v = tris_vincitore(b);
    if (v == 'O') return 1;
    if (v == 'X') return -1;
    if (tris_pieno(b)) return 0;
    int migliore = turno_o ? -2 : 2;
    for (int i = 0; i < 9; i++) {
        if (a(b, i) != ' ') continue;
        b[i / 3][i % 3] = turno_o ? 'O' : 'X';
        int valore = minimax(b, !turno_o);
        b[i / 3][i % 3] = ' ';
        if (turno_o && valore > migliore) migliore = valore;
        if (!turno_o && valore < migliore) migliore = valore;
    }
    return migliore;
}

void tris_mossa_bot(char b[3][3], int difficile) {
    int scelta = -1;
    if (difficile) {
        int migliore = -2;
        for (int i = 0; i < 9; i++) {
            if (a(b, i) != ' ') continue;
            b[i / 3][i % 3] = 'O';
            int valore = minimax(b, 0);
            b[i / 3][i % 3] = ' ';
            if (valore > migliore) {
                migliore = valore;
                scelta = i;
            }
        }
    } else {
        scelta = mossa_che_chiude(b, 'O');
        if (scelta < 0) {
            int liberi[9], n = 0;
            for (int i = 0; i < 9; i++) {
                if (a(b, i) == ' ') liberi[n++] = i;
            }
            if (n > 0) scelta = liberi[rand() % n];
        }
    }
    if (scelta >= 0) b[scelta / 3][scelta % 3] = 'O';
}

static void disegna(const char b[3][3], int cursore, const char *turno) {
    console_pulisci();
    printf("TRIS    %s\n", turno);
    printf("Frecce per muovere il cursore, Invio per giocare\n\n");
    for (int r = 0; r < 3; r++) {
        printf(" ");
        for (int c = 0; c < 3; c++) {
            int qui = r * 3 + c == cursore;
            char cella = b[r][c] == ' ' ? '.' : b[r][c];
            printf(qui ? "[%c]" : " %c ", cella);
        }
        printf("\n");
    }
}

int tris_gioca(int contro_bot, int difficile) {
    char b[3][3];
    memset(b, ' ', sizeof b);
    int cursore = 4;
    int turno_x = 1;

    for (;;) {
        disegna(b, cursore, turno_x ? "Turno di X" : (contro_bot ? "Turno del bot" : "Turno di O"));
        if (!turno_x && contro_bot) {
            tris_mossa_bot(b, difficile);
            turno_x = 1;
        } else switch (console_tasto()) {
            case TASTO_SU: if (cursore >= 3) cursore -= 3; break;
            case TASTO_GIU: if (cursore <= 5) cursore += 3; break;
            case TASTO_SINISTRA: if (cursore % 3 > 0) cursore--; break;
            case TASTO_DESTRA: if (cursore % 3 < 2) cursore++; break;
            case TASTO_INVIO:
                if (b[cursore / 3][cursore % 3] != ' ') break;
                b[cursore / 3][cursore % 3] = turno_x ? 'X' : 'O';
                turno_x = !turno_x;
                break;
            case TASTO_ESC: return -1;
            default: break;
        }
        char v = tris_vincitore(b);
        if (v == 'X' || v == 'O' || tris_pieno(b)) {
            int esito = v == 'X' ? 0 : v == 'O' ? 1 : 2;
            const char *testo = esito == 0 ? "Vince X" : esito == 1 ? (contro_bot ? "Vince il bot" : "Vince O") : "Pareggio";
            punteggio_registra("Tris", contro_bot, esito);
            char riepilogo[80];
            punteggio_testo("Tris", contro_bot, riepilogo, sizeof riepilogo);
            disegna(b, -1, testo);
            printf("\n%s\n", riepilogo);
            console_attendi_invio();
            return esito;
        }
    }
}
