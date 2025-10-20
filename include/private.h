#ifndef READLINE_PRIVATE_H
#define READLINE_PRIVATE_H

#include <termios.h>
#include <fcntl.h>
#include <signal.h>

typedef struct {
	struct termios tty;
	int width;
	int height;
	int is_init;
	int old_stdin_flags;
	struct {
		int signal
		void *old_func;
	} signals[7];
} readline_info_t;

#endif
