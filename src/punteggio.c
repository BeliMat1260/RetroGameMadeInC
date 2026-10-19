#include "punteggio.h"
#include "console.h"

#include <stdio.h>

static const char *FILE_PUNTEGGI = "punteggio.txt";

void punteggio_registra(const char *gioco, int esito) {
    FILE *out = fopen(FILE_PUNTEGGI, "a");
    if (out == NULL) return;
    const char *riga = esito == 0 ? "1-0" : esito == 1 ? "0-1" : "0-0";
    fprintf(out, "%s %s\n", gioco, riga);
    fclose(out);
}

void punteggio_mostra(void) {
    console_pulisci();
    printf("PUNTEGGI  (1-0 vince il giocatore 1, 0-1 vince l'altro, 0-0 pareggio)\n\n");
    FILE *in = fopen(FILE_PUNTEGGI, "r");
    if (in == NULL) {
        printf("Nessuna partita registrata.\n");
    } else {
        char riga[128];
        int totale = 0;
        while (fgets(riga, sizeof riga, in) != NULL) {
            printf("%s", riga);
            totale++;
        }
        fclose(in);
        printf("\n%d partite.\n", totale);
    }
    console_attendi_invio();
}
