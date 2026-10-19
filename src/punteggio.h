#ifndef PUNTEGGIO_H
#define PUNTEGGIO_H

#include <stddef.h>

/* esito: 0 vince il giocatore 1, 1 vince l'avversario, 2 pareggio.
   Le partite abbandonate non vanno registrate. */
void punteggio_registra(const char *gioco, int contro_bot, int esito);
void punteggio_testo(const char *gioco, int contro_bot, char *buf, size_t n);
void punteggio_mostra(void);

/* Solo per i test: NULL torna al file normale. */
void punteggio_usa_file(const char *percorso);

#endif
