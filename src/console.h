#ifndef CONSOLE_H
#define CONSOLE_H

typedef enum {
    TASTO_SU,
    TASTO_GIU,
    TASTO_SINISTRA,
    TASTO_DESTRA,
    TASTO_INVIO,
    TASTO_ESC,
    TASTO_ROTAZIONE,
    TASTO_ALTRO
} Tasto;

void console_pulisci(void);
void console_cursore(int riga, int colonna);
Tasto console_tasto(void);
void console_attendi_invio(void);

#endif
