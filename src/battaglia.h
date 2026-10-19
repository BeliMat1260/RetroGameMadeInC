#ifndef BATTAGLIA_H
#define BATTAGLIA_H

#define BN_LATO 10

typedef struct {
    const char *nome;
    int lunghezza;
} Nave;

/* Stesse navi del programma originale. */
extern const Nave NAVI[];
extern const int NAVI_NUMERO;

int battaglia_gioca(int contro_bot);
int battaglia_mira(const char colpi[BN_LATO][BN_LATO], int *riga, int *colonna);

int battaglia_sta(const char g[BN_LATO][BN_LATO], int riga, int colonna, int lunghezza, int orizzontale);
void battaglia_piazza(char g[BN_LATO][BN_LATO], int riga, int colonna, int lunghezza, int orizzontale);
int battaglia_piazza_bot(char g[BN_LATO][BN_LATO]);

#endif
