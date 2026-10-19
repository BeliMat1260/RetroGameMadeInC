# RetroGameMadeInC

Tris, Forza 4 e Battaglia navale da terminale, in C.

Si gioca con le frecce e Invio. Il menu, il cursore del tris, la colonna del Forza 4 e le griglie della battaglia navale non chiedono più coordinate da tastiera.

## Comandi

| Tasto | Effetto |
| --- | --- |
| Frecce | Muovono la selezione |
| Invio | Conferma la mossa |
| R | Ruota la nave, durante il piazzamento |
| Esc | Esce dal tris e dal Forza 4 |

## Giochi

- **Tris** 3x3, giocatore contro giocatore oppure contro il bot. Il bot difficile chiude una riga e blocca quella dell'avversario.
- **Forza 4** 6x7. Il gettone cade nella colonna scelta. Il bot difficile chiude e blocca.
- **Battaglia navale** 10x10, con le stesse navi dell'originale: sottomarino (3), incrociatore (4), cacciatorpediniere (2), portaerei (5). In due si passa il computer tra un turno e l'altro, così l'avversario non vede le navi.

I risultati finiscono in `punteggio.txt`: `1-0` vince il giocatore 1, `0-1` vince l'altro, `0-0` pareggio.

## Build

Serve GCC (su Windows, MinGW).

```bash
make
./retrogame.exe
```

Senza make:

```bash
gcc -std=c11 -Wall -Wextra -Isrc -o retrogame.exe src/*.c
```

I test della logica (vittoria, gravità dei gettoni, piazzamento delle navi):

```bash
make test
```

## Struttura

| File | Ruolo |
| --- | --- |
| `src/main.c` | Menu |
| `src/tris.c` | Tris e bot |
| `src/forza4.c` | Forza 4 e bot |
| `src/battaglia.c` | Piazzamento, tiro, bot |
| `src/console.c` | Schermo e tasti |
| `src/punteggio.c` | Storico delle partite |
