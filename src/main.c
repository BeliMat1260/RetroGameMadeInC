#include "console.h"
#include "tris.h"
#include "forza4.h"
#include "battaglia.h"
#include "punteggio.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int scegli(const char *titolo, const char **voci, int numero) {
    int selezionata = 0;
    for (;;) {
        console_pulisci();
        printf("%s\n\n", titolo);
        for (int i = 0; i < numero; i++) {
            printf(i == selezionata ? " > %s\n" : "   %s\n", voci[i]);
        }
        printf("\nFrecce su/giu, Invio per confermare");
        switch (console_tasto()) {
            case TASTO_SU: if (selezionata > 0) selezionata--; break;
            case TASTO_GIU: if (selezionata < numero - 1) selezionata++; break;
            case TASTO_INVIO: return selezionata;
            case TASTO_ESC: return -1;
            default: break;
        }
    }
}

static int difficolta(void) {
    const char *voci[] = {"Facile: mosse a caso", "Difficile: chiude e blocca"};
    int scelta = scegli("DIFFICOLTA DEL BOT", voci, 2);
    return scelta < 0 ? 0 : scelta;
}

static void partita(const char *nome, int esito) {
    punteggio_registra(nome, esito);
}

int main(void) {
    srand((unsigned)time(NULL));
    const char *voci[] = {
        "Tris, giocatore contro giocatore",
        "Tris, contro il bot",
        "Forza 4, giocatore contro giocatore",
        "Forza 4, contro il bot",
        "Battaglia navale, giocatore contro giocatore",
        "Battaglia navale, contro il bot",
        "Punteggi",
        "Esci"
    };

    for (;;) {
        int scelta = scegli("RETRO GAME    Tris, Forza 4, Battaglia navale", voci, 8);
        int esito = 2;
        switch (scelta) {
            case 0: esito = tris_gioca(0, 0); partita("Tris", esito); break;
            case 1: esito = tris_gioca(1, difficolta()); partita("Tris", esito); break;
            case 2: esito = forza4_gioca(0, 0); partita("Forza4", esito); break;
            case 3: esito = forza4_gioca(1, difficolta()); partita("Forza4", esito); break;
            case 4: esito = battaglia_gioca(0); punteggio_registra("Battaglia", esito); break;
            case 5: esito = battaglia_gioca(1); punteggio_registra("Battaglia", esito); break;
            case 6: punteggio_mostra(); break;
            default: return 0;
        }
    }
}
