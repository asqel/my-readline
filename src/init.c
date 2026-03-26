#include "private.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

readline_info_t readline_info = {0};

static int init_tty() {
	readline_info.tty.fd = open("/dev/tty", O_RDWR);
	if (readline_info.tty.fd < 0)
		return 1;
	struct termios tty;
	tcgetattr(readline_info.tty.fd, &readline_info.tty.old_tty);
	tty = readline_info.tty.old_tty;
	tty.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(readline_info.tty.fd, TCSANOW, &tty);
	return 0;
}

int readline_init() {
	if (init_tty())
		return 1;
	readline_info.is_init = 1;
	write(1, "\e[?2004h", 8);
	return 0;
}


