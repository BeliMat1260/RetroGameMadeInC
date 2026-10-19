#include "tris.h"
#include "forza4.h"
#include "battaglia.h"
#include "punteggio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int fallimenti = 0;

static void verifica(int condizione, const char *nome) {
    if (!condizione) {
        fallimenti++;
        printf("FAIL %s\n", nome);
    }
}

static void test_tris(void) {
    char b[3][3];
    memset(b, ' ', sizeof b);
    verifica(tris_vincitore(b) == ' ', "griglia vuota senza vincitore");
    b[0][0] = b[0][1] = b[0][2] = 'X';
    verifica(tris_vincitore(b) == 'X', "riga di X");
    memset(b, ' ', sizeof b);
    b[0][2] = b[1][1] = b[2][0] = 'O';
    verifica(tris_vincitore(b) == 'O', "diagonale di O");
    memset(b, 'O', sizeof b);
    b[0][0] = ' ';
    tris_mossa_bot(b, 1);
    verifica(b[0][0] == 'O' && tris_vincitore(b) == 'O', "bot difficile chiude");
    memset(b, ' ', sizeof b);
    b[0][0] = b[0][1] = 'X';
    tris_mossa_bot(b, 1);
    verifica(b[0][2] == 'O', "bot difficile blocca");
}

static void test_forza4(void) {
    char b[F4_RIGHE][F4_COLONNE];
    memset(b, ' ', sizeof b);
    verifica(forza4_caduta(b, 3, 'O') == 5, "il gettone cade in fondo");
    verifica(forza4_caduta(b, 3, 'X') == 4, "il secondo gettone si appoggia");
    verifica(forza4_caduta(b, 9, 'O') == -1, "colonna inesistente rifiutata");
    for (int i = 0; i < 4; i++) forza4_caduta(b, 0, 'O');
    verifica(forza4_vince(b, 'O'), "quattro in verticale");
    memset(b, ' ', sizeof b);
    for (int c = 0; c < 3; c++) forza4_caduta(b, c, 'X');
    verifica(forza4_colonna_bot(b, 1) == 3, "bot difficile chiude in orizzontale");
}

static void test_battaglia(void) {
    char g[BN_LATO][BN_LATO];
    memset(g, ' ', sizeof g);
    verifica(battaglia_sta(g, 0, 0, 5, 1), "portaerei orizzontale in angolo");
    verifica(!battaglia_sta(g, 0, 7, 5, 1), "portaerei che esce dal bordo");
    battaglia_piazza(g, 0, 0, 3, 1);
    verifica(!battaglia_sta(g, 0, 2, 2, 1), "nave sovrapposta rifiutata");
    srand(1);
    char bot[BN_LATO][BN_LATO];
    verifica(battaglia_piazza_bot(bot), "il bot piazza tutte le navi");
    int celle = 0;
    for (int r = 0; r < BN_LATO; r++) {
        for (int c = 0; c < BN_LATO; c++) {
            if (bot[r][c] == '#') celle++;
        }
    }
    verifica(celle == 3 + 4 + 2 + 5, "14 caselle di nave");
}

static void test_mira(void) {
    char colpi[BN_LATO][BN_LATO];
    int r, c;
    memset(colpi, ' ', sizeof colpi);
    colpi[4][4] = 'X';
    colpi[4][5] = 'X';
    verifica(battaglia_mira(colpi, &r, &c), "il bot trova un bersaglio");
    verifica((r == 4 && c == 6) || (r == 4 && c == 3), "il bot prosegue sulla nave");
    memset(colpi, ' ', sizeof colpi);
    colpi[2][2] = 'X';
    battaglia_mira(colpi, &r, &c);
    int adiacente = (r == 1 && c == 2) || (r == 3 && c == 2) || (r == 2 && c == 1) || (r == 2 && c == 3);
    verifica(adiacente, "dopo un colpo il bot spara accanto");
}

static void test_punteggio(void) {
    const char *file = "punteggio_test.txt";
    remove(file);
    punteggio_usa_file(file);
    punteggio_registra("Tris", 1, 0);
    punteggio_registra("Tris", 1, 1);
    punteggio_registra("Tris", 0, 0);
    punteggio_registra("Tris", 1, -1);
    char testo[80];
    punteggio_testo("Tris", 1, testo, sizeof testo);
    verifica(strcmp(testo, "Contro il bot: tu 1, bot 1, pareggi 0") == 0, "il punteggio contro il bot viene contato");
    punteggio_testo("Tris", 0, testo, sizeof testo);
    verifica(strcmp(testo, "Tu 1, avversario 0, pareggi 0") == 0, "la partita tra giocatori resta separata");
    punteggio_usa_file(NULL);
    remove(file);
}

int main(void) {
    srand(1);
    test_tris();
    test_forza4();
    test_battaglia();
    test_mira();
    test_punteggio();
    printf(fallimenti == 0 ? "ALL PASS\n" : "%d failures\n", fallimenti);
    return fallimenti == 0 ? 0 : 1;
}
