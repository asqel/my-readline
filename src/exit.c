#include "private.h"

static void exit_tty() {
	tcsetattr(readline_info.tty.fd, TCSANOW, &readline_info.tty.old_tty);
	close(readline_info.tty.fd);
	readline_info.tty.fd = -1;
}

void readline_exit() {
	exit_tty();
	readline_info.is_init = 0;
	write(1, "\e[?2004l", 8);
}
