#include "punteggio.h"
#include "console.h"

#include <stdio.h>
#include <string.h>

static const char *file_forzato = NULL;

static const char *file_punteggi(void) {
    return file_forzato != NULL ? file_forzato : "punteggio.txt";
}

void punteggio_usa_file(const char *percorso) {
    file_forzato = percorso;
}

static void conteggia(const char *gioco, int contro_bot, int *vittorie, int *sconfitte, int *pareggi) {
    *vittorie = *sconfitte = *pareggi = 0;
    FILE *in = fopen(file_punteggi(), "r");
    if (in == NULL) return;
    char riga[160];
    const char *contro = contro_bot ? "bot" : "giocatore";
    while (fgets(riga, sizeof riga, in) != NULL) {
        char nome[32], avversario[32], risultato[8];
        if (sscanf(riga, "%31s vs %31s %7s", nome, avversario, risultato) != 3) continue;
        if (strcmp(nome, gioco) != 0 || strcmp(avversario, contro) != 0) continue;
        if (strcmp(risultato, "1-0") == 0) (*vittorie)++;
        else if (strcmp(risultato, "0-1") == 0) (*sconfitte)++;
        else if (strcmp(risultato, "0-0") == 0) (*pareggi)++;
    }
    fclose(in);
}

void punteggio_registra(const char *gioco, int contro_bot, int esito) {
    if (esito < 0 || esito > 2) return;
    FILE *out = fopen(file_punteggi(), "a");
    if (out == NULL) return;
    const char *risultato = esito == 0 ? "1-0" : esito == 1 ? "0-1" : "0-0";
    fprintf(out, "%s vs %s %s\n", gioco, contro_bot ? "bot" : "giocatore", risultato);
    fclose(out);
}

void punteggio_testo(const char *gioco, int contro_bot, char *buf, size_t n) {
    int vittorie, sconfitte, pareggi;
    conteggia(gioco, contro_bot, &vittorie, &sconfitte, &pareggi);
    if (contro_bot) {
        snprintf(buf, n, "Contro il bot: tu %d, bot %d, pareggi %d", vittorie, sconfitte, pareggi);
    } else {
        snprintf(buf, n, "Tu %d, avversario %d, pareggi %d", vittorie, sconfitte, pareggi);
    }
}

void punteggio_mostra(void) {
    console_pulisci();
    printf("PUNTEGGI\n\n");
    const char *giochi[] = {"Tris", "Forza4", "Battaglia"};
    for (int g = 0; g < 3; g++) {
        char umano[80], bot[80];
        punteggio_testo(giochi[g], 0, umano, sizeof umano);
        punteggio_testo(giochi[g], 1, bot, sizeof bot);
        printf("%s\n  %s\n  %s\n\n", giochi[g], umano, bot);
    }
    printf("Registro:\n");
    FILE *in = fopen(file_punteggi(), "r");
    if (in == NULL) {
        printf("Nessuna partita conclusa.\n");
    } else {
        char riga[160];
        int totale = 0;
        while (fgets(riga, sizeof riga, in) != NULL) {
            printf("  %s", riga);
            totale++;
        }
        fclose(in);
        if (totale == 0) printf("Nessuna partita conclusa.\n");
    }
    console_attendi_invio();
}
