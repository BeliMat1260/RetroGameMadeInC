#ifndef TRIS_H
#define TRIS_H

/* 0 = vince il giocatore 1 (X), 1 = vince il giocatore 2 / bot (O), 2 = pareggio */
int tris_gioca(int contro_bot, int difficile);

char tris_vincitore(const char b[3][3]);
int tris_pieno(const char b[3][3]);
void tris_mossa_bot(char b[3][3], int difficile);

#endif
