#include "forza4.h"
#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int forza4_caduta(char b[F4_RIGHE][F4_COLONNE], int colonna, char segno) {
    if (colonna < 0 || colonna >= F4_COLONNE || b[0][colonna] != ' ') return -1;
    int riga = F4_RIGHE - 1;
    while (riga > 0 && b[riga][colonna] != ' ') riga--;
    b[riga][colonna] = segno;
    return riga;
}

static int quattro(char a, char b, char c, char d, char segno) {
    return a == segno && b == segno && c == segno && d == segno;
}

int forza4_vince(const char b[F4_RIGHE][F4_COLONNE], char segno) {
    for (int r = 0; r < F4_RIGHE; r++) {
        for (int c = 0; c <= F4_COLONNE - 4; c++) {
            if (quattro(b[r][c], b[r][c + 1], b[r][c + 2], b[r][c + 3], segno)) return 1;
        }
    }
    for (int c = 0; c < F4_COLONNE; c++) {
        for (int r = 0; r <= F4_RIGHE - 4; r++) {
            if (quattro(b[r][c], b[r + 1][c], b[r + 2][c], b[r + 3][c], segno)) return 1;
        }
    }
    for (int r = 0; r <= F4_RIGHE - 4; r++) {
        for (int c = 0; c <= F4_COLONNE - 4; c++) {
            if (quattro(b[r][c], b[r + 1][c + 1], b[r + 2][c + 2], b[r + 3][c + 3], segno)) return 1;
        }
    }
    for (int r = 3; r < F4_RIGHE; r++) {
        for (int c = 0; c <= F4_COLONNE - 4; c++) {
            if (quattro(b[r][c], b[r - 1][c + 1], b[r - 2][c + 2], b[r - 3][c + 3], segno)) return 1;
        }
    }
    return 0;
}

static int pieno(const char b[F4_RIGHE][F4_COLONNE]) {
    for (int c = 0; c < F4_COLONNE; c++) {
        if (b[0][c] == ' ') return 0;
    }
    return 1;
}

/* Colonna che, se giocata da segno, chiude la partita. -1 se non esiste. */
static int colonna_vincente(const char b[F4_RIGHE][F4_COLONNE], char segno) {
    for (int c = 0; c < F4_COLONNE; c++) {
        char copia[F4_RIGHE][F4_COLONNE];
        memcpy(copia, b, sizeof copia);
        if (forza4_caduta(copia, c, segno) >= 0 && forza4_vince(copia, segno)) return c;
    }
    return -1;
}

int forza4_colonna_bot(const char b[F4_RIGHE][F4_COLONNE], int difficile) {
    if (difficile) {
        int vince = colonna_vincente(b, 'X');
        if (vince >= 0) return vince;
        int blocca = colonna_vincente(b, 'O');
        if (blocca >= 0) return blocca;
    }
    int libere[F4_COLONNE], n = 0;
    for (int c = 0; c < F4_COLONNE; c++) {
        if (b[0][c] == ' ') libere[n++] = c;
    }
    if (n == 0) return -1;
    /* Preferisce il centro quando la colonna centrale e' tra le libere. */
    for (int i = 0; i < n; i++) {
        if (libere[i] == F4_COLONNE / 2 && rand() % 2 == 0) return libere[i];
    }
    return libere[rand() % n];
}

static void disegna(const char b[F4_RIGHE][F4_COLONNE], int colonna, const char *turno) {
    console_pulisci();
    printf("FORZA 4    %s\n", turno);
    printf("Giocatore 1: O    Giocatore 2: X\n");
    printf("Frecce per scegliere la colonna, Invio per far cadere il gettone\n\n");
    printf(" ");
    for (int c = 0; c < F4_COLONNE; c++) printf(c == colonna ? " v" : "  ");
    printf("\n");
    for (int r = 0; r < F4_RIGHE; r++) {
        printf("|");
        for (int c = 0; c < F4_COLONNE; c++) {
            printf("%c|", b[r][c] == ' ' ? '.' : b[r][c]);
        }
        printf("\n");
    }
}

int forza4_gioca(int contro_bot, int difficile) {
    char b[F4_RIGHE][F4_COLONNE];
    memset(b, ' ', sizeof b);
    int colonna = 3;
    int turno_o = 1;

    for (;;) {
        const char *chi = turno_o ? "Turno di O" : (contro_bot ? "Turno del bot" : "Turno di X");
        disegna(b, colonna, chi);
        if (!turno_o && contro_bot) {
            int scelta = forza4_colonna_bot(b, difficile);
            forza4_caduta(b, scelta, 'X');
            turno_o = 1;
        } else {
            int giocata = 0;
            switch (console_tasto()) {
                case TASTO_SINISTRA: if (colonna > 0) colonna--; break;
                case TASTO_DESTRA: if (colonna < F4_COLONNE - 1) colonna++; break;
                case TASTO_INVIO:
                    if (forza4_caduta(b, colonna, turno_o ? 'O' : 'X') >= 0) giocata = 1;
                    break;
                case TASTO_ESC: return 2;
                default: break;
            }
            if (!giocata) continue;
            turno_o = !turno_o;
        }
        if (forza4_vince(b, 'O') || forza4_vince(b, 'X') || pieno(b)) {
            char v = forza4_vince(b, 'O') ? 'O' : forza4_vince(b, 'X') ? 'X' : ' ';
            const char *esito = v == 'O' ? "Vince O" : v == 'X' ? (contro_bot ? "Vince il bot" : "Vince X") : "Pareggio";
            disegna(b, -1, esito);
            console_attendi_invio();
            return v == 'O' ? 0 : v == 'X' ? 1 : 2;
        }
    }
}
