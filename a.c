#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>

void handle_winch(int sig) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf("Nouvelle taille : %d lignes, %d colonnes\n", w.ws_row, w.ws_col);
}

int main() {
    signal(SIGWINCH, handle_winch);
    printf("Redimensionnez le terminal pour voir le signal.\n");
    while (1) pause(); // Attente du signal
    return 0;
}

