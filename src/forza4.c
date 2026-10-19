#include "forza4.h"
#include "console.h"
#include "punteggio.h"

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

static int valuta(const char f[4]) {
    int miei = 0, suoi = 0;
    for (int i = 0; i < 4; i++) {
        if (f[i] == 'X') miei++;
        else if (f[i] == 'O') suoi++;
    }
    if (miei && suoi) return 0;
    if (miei == 4) return 100;
    if (suoi == 4) return -100;
    if (miei == 3) return 12;
    if (suoi == 3) return -10;
    if (miei == 2) return 3;
    if (suoi == 2) return -2;
    return 0;
}

static int euristica(char b[F4_RIGHE][F4_COLONNE]) {
    int totale = 0;
    char finestre[4];
    for (int r = 0; r < F4_RIGHE; r++) {
        for (int c = 0; c < F4_COLONNE; c++) {
            if (c <= F4_COLONNE - 4) {
                for (int i = 0; i < 4; i++) finestre[i] = b[r][c + i];
                totale += valuta(finestre);
            }
            if (r <= F4_RIGHE - 4) {
                for (int i = 0; i < 4; i++) finestre[i] = b[r + i][c];
                totale += valuta(finestre);
            }
            if (r <= F4_RIGHE - 4 && c <= F4_COLONNE - 4) {
                for (int i = 0; i < 4; i++) finestre[i] = b[r + i][c + i];
                totale += valuta(finestre);
            }
            if (r >= 3 && c <= F4_COLONNE - 4) {
                for (int i = 0; i < 4; i++) finestre[i] = b[r - i][c + i];
                totale += valuta(finestre);
            }
        }
    }
    return totale;
}

static void annulla(char b[F4_RIGHE][F4_COLONNE], int colonna) {
    for (int r = 0; r < F4_RIGHE; r++) {
        if (b[r][colonna] != ' ') {
            b[r][colonna] = ' ';
            return;
        }
    }
}

static int cerca(char b[F4_RIGHE][F4_COLONNE], int profondita, int alfa, int beta, int turno_x) {
    if (forza4_vince(b, 'X')) return 100000 + profondita;
    if (forza4_vince(b, 'O')) return -100000 - profondita;
    if (profondita == 0 || pieno(b)) return euristica(b);
    static const int ordine[] = {3, 2, 4, 1, 5, 0, 6};
    int migliore = turno_x ? -1000000 : 1000000;
    for (int i = 0; i < F4_COLONNE; i++) {
        int colonna = ordine[i];
        if (forza4_caduta(b, colonna, turno_x ? 'X' : 'O') < 0) continue;
        int valore = cerca(b, profondita - 1, alfa, beta, !turno_x);
        annulla(b, colonna);
        if (turno_x && valore > migliore) migliore = valore;
        if (!turno_x && valore < migliore) migliore = valore;
        if (turno_x && valore > alfa) alfa = valore;
        if (!turno_x && valore < beta) beta = valore;
        if (alfa >= beta) break;
    }
    return migliore == 1000000 || migliore == -1000000 ? 0 : migliore;
}

int forza4_colonna_bot(const char b[F4_RIGHE][F4_COLONNE], int difficile) {
    char copia[F4_RIGHE][F4_COLONNE];
    static const int ordine[] = {3, 2, 4, 1, 5, 0, 6};
    if (!difficile) {
        int libere[F4_COLONNE], n = 0;
        for (int i = 0; i < F4_COLONNE; i++) {
            int colonna = ordine[i];
            memcpy(copia, b, sizeof copia);
            if (forza4_caduta(copia, colonna, 'X') < 0) continue;
            if (forza4_vince(copia, 'X')) return colonna;
            libere[n++] = colonna;
        }
        return n == 0 ? -1 : libere[rand() % n];
    }
    int scelta = -1;
    int migliore = -1000000;
    for (int i = 0; i < F4_COLONNE; i++) {
        int colonna = ordine[i];
        memcpy(copia, b, sizeof copia);
        if (forza4_caduta(copia, colonna, 'X') < 0) continue;
        int valore = cerca(copia, 5, -1000000, 1000000, 0);
        if (valore > migliore) {
            migliore = valore;
            scelta = colonna;
        }
    }
    return scelta;
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
                case TASTO_ESC: return -1;
                default: break;
            }
            if (!giocata) continue;
            turno_o = !turno_o;
        }
        if (forza4_vince(b, 'O') || forza4_vince(b, 'X') || pieno(b)) {
            int esito = forza4_vince(b, 'O') ? 0 : forza4_vince(b, 'X') ? 1 : 2;
            const char *testo = esito == 0 ? "Vince O" : esito == 1 ? (contro_bot ? "Vince il bot" : "Vince X") : "Pareggio";
            punteggio_registra("Forza4", contro_bot, esito);
            char riepilogo[80];
            punteggio_testo("Forza4", contro_bot, riepilogo, sizeof riepilogo);
            disegna(b, -1, testo);
            printf("\n%s\n", riepilogo);
            console_attendi_invio();
            return esito;
        }
    }
}
