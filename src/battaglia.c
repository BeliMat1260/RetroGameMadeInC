#include "battaglia.h"
#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const Nave NAVI[] = {
    {"Sottomarino", 3},
    {"Incrociatore", 4},
    {"Cacciatorpediniere", 2},
    {"Portaerei", 5}
};
const int NAVI_NUMERO = 4;

int battaglia_sta(const char g[BN_LATO][BN_LATO], int riga, int colonna, int lunghezza, int orizzontale) {
    for (int i = 0; i < lunghezza; i++) {
        int r = riga + (orizzontale ? 0 : i);
        int c = colonna + (orizzontale ? i : 0);
        if (r < 0 || r >= BN_LATO || c < 0 || c >= BN_LATO || g[r][c] != ' ') return 0;
    }
    return 1;
}

void battaglia_piazza(char g[BN_LATO][BN_LATO], int riga, int colonna, int lunghezza, int orizzontale) {
    for (int i = 0; i < lunghezza; i++) {
        int r = riga + (orizzontale ? 0 : i);
        int c = colonna + (orizzontale ? i : 0);
        g[r][c] = '#';
    }
}

int battaglia_piazza_bot(char g[BN_LATO][BN_LATO]) {
    for (int tentativi = 0; tentativi < 1000; tentativi++) {
        char prova[BN_LATO][BN_LATO];
        memset(prova, ' ', sizeof prova);
        int ok = 1;
        for (int n = 0; n < NAVI_NUMERO && ok; n++) {
            int piazzata = 0;
            for (int t = 0; t < 200 && !piazzata; t++) {
                int orizzontale = rand() % 2;
                int riga = rand() % BN_LATO;
                int colonna = rand() % BN_LATO;
                if (battaglia_sta(prova, riga, colonna, NAVI[n].lunghezza, orizzontale)) {
                    battaglia_piazza(prova, riga, colonna, NAVI[n].lunghezza, orizzontale);
                    piazzata = 1;
                }
            }
            if (!piazzata) ok = 0;
        }
        if (ok) {
            memcpy(g, prova, sizeof prova);
            return 1;
        }
    }
    return 0;
}

static int celle_nave(const char g[BN_LATO][BN_LATO]) {
    int n = 0;
    for (int r = 0; r < BN_LATO; r++) {
        for (int c = 0; c < BN_LATO; c++) {
            if (g[r][c] == '#') n++;
        }
    }
    return n;
}

static void disegna_griglia(const char g[BN_LATO][BN_LATO], int cr, int cc, int mostra_navi) {
    printf("   ");
    for (int c = 0; c < BN_LATO; c++) printf(" %c", 'A' + c);
    printf("\n");
    for (int r = 0; r < BN_LATO; r++) {
        printf("%2d ", r + 1);
        for (int c = 0; c < BN_LATO; c++) {
            char cella = g[r][c];
            if (!mostra_navi && cella == '#') cella = ' ';
            if (cella == ' ') cella = '.';
            printf(r == cr && c == cc ? "[%c]" : " %c ", cella);
        }
        printf("\n");
    }
}

static void piazza_umano(char g[BN_LATO][BN_LATO], const char *chi) {
    int riga = 0, colonna = 0, orizzontale = 1;
    for (int n = 0; n < NAVI_NUMERO; n++) {
        for (;;) {
            console_pulisci();
            printf("BATTAGLIA NAVALE    %s piazza le navi\n", chi);
            printf("%s (%d caselle)    %s    R ruota, Invio conferma\n\n",
                   NAVI[n].nome, NAVI[n].lunghezza, orizzontale ? "orizzontale" : "verticale");
            disegna_griglia(g, riga, colonna, 1);
            switch (console_tasto()) {
                case TASTO_SU: if (riga > 0) riga--; break;
                case TASTO_GIU: if (riga < BN_LATO - 1) riga++; break;
                case TASTO_SINISTRA: if (colonna > 0) colonna--; break;
                case TASTO_DESTRA: if (colonna < BN_LATO - 1) colonna++; break;
                case TASTO_ROTAZIONE: orizzontale = !orizzontale; break;
                case TASTO_INVIO:
                    if (battaglia_sta(g, riga, colonna, NAVI[n].lunghezza, orizzontale)) {
                        battaglia_piazza(g, riga, colonna, NAVI[n].lunghezza, orizzontale);
                        goto prossima;
                    }
                    break;
                default: break;
            }
        }
        prossima:;
    }
}

/* 1 se il colpo e' andato a segno. */
static int spara(char navi[BN_LATO][BN_LATO], char colpi[BN_LATO][BN_LATO], int r, int c) {
    if (colpi[r][c] != ' ') return 0;
    int centro = navi[r][c] == '#';
    colpi[r][c] = centro ? 'X' : 'o';
    if (centro) navi[r][c] = 'X';
    return centro;
}

static int colpi_a_segno(const char colpi[BN_LATO][BN_LATO]) {
    int n = 0;
    for (int r = 0; r < BN_LATO; r++) {
        for (int c = 0; c < BN_LATO; c++) {
            if (colpi[r][c] == 'X') n++;
        }
    }
    return n;
}

static void turno_umano(char navi_avversario[BN_LATO][BN_LATO], char colpi[BN_LATO][BN_LATO],
                        const char proprie[BN_LATO][BN_LATO], const char *chi, int bersaglio) {
    int riga = 0, colonna = 0;
    for (;;) {
        console_pulisci();
        printf("BATTAGLIA NAVALE    %s    colpi a segno: %d/%d\n", chi, colpi_a_segno(colpi), bersaglio);
        printf("Le tue navi:\n");
        disegna_griglia(proprie, -1, -1, 1);
        printf("\nGriglia di tiro (X colpito, o acqua). Frecce e Invio:\n");
        disegna_griglia(colpi, riga, colonna, 0);
        switch (console_tasto()) {
            case TASTO_SU: if (riga > 0) riga--; break;
            case TASTO_GIU: if (riga < BN_LATO - 1) riga++; break;
            case TASTO_SINISTRA: if (colonna > 0) colonna--; break;
            case TASTO_DESTRA: if (colonna < BN_LATO - 1) colonna++; break;
            case TASTO_INVIO:
                if (colpi[riga][colonna] == ' ') {
                    spara(navi_avversario, colpi, riga, colonna);
                    return;
                }
                break;
            default: break;
        }
    }
}

static void turno_bot(char navi[BN_LATO][BN_LATO], char colpi[BN_LATO][BN_LATO]) {
    int r, c;
    do {
        r = rand() % BN_LATO;
        c = rand() % BN_LATO;
    } while (colpi[r][c] != ' ');
    spara(navi, colpi, r, c);
}

int battaglia_gioca(int contro_bot) {
    char navi1[BN_LATO][BN_LATO], navi2[BN_LATO][BN_LATO];
    char colpi1[BN_LATO][BN_LATO], colpi2[BN_LATO][BN_LATO];
    memset(navi1, ' ', sizeof navi1);
    memset(navi2, ' ', sizeof navi2);
    memset(colpi1, ' ', sizeof colpi1);
    memset(colpi2, ' ', sizeof colpi2);

    piazza_umano(navi1, "Giocatore 1");
    if (contro_bot) {
        if (!battaglia_piazza_bot(navi2)) return 2;
    } else {
        console_pulisci();
        printf("Passa il computer al giocatore 2.");
        console_attendi_invio();
        piazza_umano(navi2, "Giocatore 2");
    }

    int bersaglio = celle_nave(navi1);
    int turno1 = 1;
    for (;;) {
        if (!turno1 && contro_bot) {
            turno_bot(navi1, colpi2);
        } else {
            if (!contro_bot) {
                console_pulisci();
                printf("Turno del giocatore %d. L'altro non deve guardare.", turno1 ? 1 : 2);
                console_attendi_invio();
            }
            if (turno1) turno_umano(navi2, colpi1, navi1, "Giocatore 1", bersaglio);
            else turno_umano(navi1, colpi2, navi2, "Giocatore 2", bersaglio);
        }
        if (colpi_a_segno(colpi1) == bersaglio || colpi_a_segno(colpi2) == bersaglio) {
            int vince1 = colpi_a_segno(colpi1) == bersaglio;
            console_pulisci();
            printf(vince1 ? "Vince il giocatore 1: flotta avversaria affondata.\n"
                          : "Vince %s: la tua flotta e' affondata.\n",
                   contro_bot ? "il bot" : "il giocatore 2");
            console_attendi_invio();
            return vince1 ? 0 : 1;
        }
        turno1 = !turno1;
    }
}
