#ifndef FORZA4_H
#define FORZA4_H

#define F4_RIGHE 6
#define F4_COLONNE 7

/* 0 = vince O (giocatore 1), 1 = vince X (giocatore 2 / bot), 2 = pareggio */
int forza4_gioca(int contro_bot, int difficile);

int forza4_caduta(char b[F4_RIGHE][F4_COLONNE], int colonna, char segno);
int forza4_vince(const char b[F4_RIGHE][F4_COLONNE], char segno);
int forza4_colonna_bot(const char b[F4_RIGHE][F4_COLONNE], int difficile);

#endif
