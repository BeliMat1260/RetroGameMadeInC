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

- **Tris** 3x3. Il bot facile prende la vittoria immediata, altrimenti gioca a caso. Quello difficile guarda tutta la partita e non si fa battere se anche tu giochi bene.
- **Forza 4** 6x7. Il gettone cade nella colonna scelta. Il bot difficile guarda cinque mosse avanti, chiude e blocca.
- **Battaglia navale** 10x10, con le stesse navi dell'originale: sottomarino (3), incrociatore (4), cacciatorpediniere (2), portaerei (5). Il bot, dopo un colpo a segno, spara sulle caselle vicine e prosegue lungo la nave. In due si passa il computer tra un turno e l'altro.

A fine partita, anche contro il bot, compare il punteggio aggiornato. Esc abbandona tris e Forza 4 senza segnare nulla. Lo storico sta in `punteggio.txt`, separato tra partite contro un giocatore e contro il bot. Dal menu, **Punteggi** mostra i totali.

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
