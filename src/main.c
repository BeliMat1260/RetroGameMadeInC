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
    const char *voci[] = {"Facile", "Difficile"};
    int scelta = scegli("DIFFICOLTA DEL BOT", voci, 2);
    return scelta < 0 ? 0 : scelta;
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
        switch (scelta) {
            case 0: tris_gioca(0, 0); break;
            case 1: tris_gioca(1, difficolta()); break;
            case 2: forza4_gioca(0, 0); break;
            case 3: forza4_gioca(1, difficolta()); break;
            case 4: battaglia_gioca(0); break;
            case 5: battaglia_gioca(1); break;
            case 6: punteggio_mostra(); break;
            default: return 0;
        }
    }
}
