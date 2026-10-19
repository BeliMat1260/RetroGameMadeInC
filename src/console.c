#include "console.h"

#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void console_pulisci(void) {
#ifdef _WIN32
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    DWORD scritti;
    COORD origine = {0, 0};
    if (!GetConsoleScreenBufferInfo(out, &info)) {
        return;
    }
    DWORD celle = info.dwSize.X * info.dwSize.Y;
    FillConsoleOutputCharacter(out, ' ', celle, origine, &scritti);
    FillConsoleOutputAttribute(out, info.wAttributes, celle, origine, &scritti);
    SetConsoleCursorPosition(out, origine);
#else
    printf("\033[2J\033[H");
#endif
}

void console_cursore(int riga, int colonna) {
#ifdef _WIN32
    COORD pos = {(SHORT)colonna, (SHORT)riga};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
#else
    printf("\033[%d;%dH", riga + 1, colonna + 1);
#endif
}

Tasto console_tasto(void) {
#ifdef _WIN32
    int c = _getch();
    if (c == 0 || c == 224) {
        switch (_getch()) {
            case 72: return TASTO_SU;
            case 80: return TASTO_GIU;
            case 75: return TASTO_SINISTRA;
            case 77: return TASTO_DESTRA;
            default: return TASTO_ALTRO;
        }
    }
#else
    struct termios vecchio, nuovo;
    tcgetattr(STDIN_FILENO, &vecchio);
    nuovo = vecchio;
    nuovo.c_lflag &= (tcflag_t)~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &nuovo);
    int c = getchar();
    if (c == 27 && getchar() == '[') {
        tcsetattr(STDIN_FILENO, TCSANOW, &vecchio);
        switch (getchar()) {
            case 'A': return TASTO_SU;
            case 'B': return TASTO_GIU;
            case 'D': return TASTO_SINISTRA;
            case 'C': return TASTO_DESTRA;
            default: return TASTO_ALTRO;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &vecchio);
#endif
    if (c == '\r' || c == '\n' || c == ' ') return TASTO_INVIO;
    if (c == 27) return TASTO_ESC;
    if (c == 'r' || c == 'R') return TASTO_ROTAZIONE;
    return TASTO_ALTRO;
}

void console_attendi_invio(void) {
    printf("\nInvio per continuare...");
    for (;;) {
        if (console_tasto() == TASTO_INVIO) return;
    }
}
