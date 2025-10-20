#include "private.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*
SIGINT
SIGWINCH
SIGTSTP
SIGCONT
SIGTERM
SIGHUP
SIGQUIT
*/

readline_info_t readline_info = {0};

static int signal_from_idx(int i) {
	if (i < 0 || i >= 7)
		return -1;
	int sigs[7] = {SIGINT, SIGWINCH, SIGTSTP, SIGCONT, SIGTERM, SIGHUP, SIGQUIT};
}

int readline_init() {
	int flags = fcntl(0, F_GETFL, 0);
	if (flags == -1)
		return 1;
	readline_info.old_stdin_flags = flags;
	flags |= O_NONBLOCK;
	if (fcntl(0, F_SETFL, flags) == -1)
		return 1;
	struct termios tty;

	if (tcgetattr(0, &tty) == -1) {
		fcntl(0, F_SETFL, readline_info.old_stdin_flags);
		return 1;
	}
	readline_info.tty = tty;

	tty.c_lflag &= ~(ECHO);
	tty.c_lflag &= ~(ICANON);
	if (tcsetattr(0, TCSAFLUSH, &tty) == -1) {
		fcntl(0, F_SETFL, readline_info.old_stdin_flags);
		return 1;
	}

	return 0;
}


