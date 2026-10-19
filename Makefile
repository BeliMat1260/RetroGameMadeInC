CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Isrc
SRC = src/console.c src/tris.c src/forza4.c src/battaglia.c src/punteggio.c src/main.c

retrogame.exe: $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

test: src/tris.c src/forza4.c src/battaglia.c tests/logica.c
	$(CC) $(CFLAGS) -o test_logica.exe src/tris.c src/forza4.c src/battaglia.c tests/logica.c
	./test_logica.exe

clean:
	rm -f retrogame.exe test_logica.exe punteggio.txt
