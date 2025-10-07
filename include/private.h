#ifndef READLINE_PRIVATE_H
#define READLINE_PRIVATE_H

#include <termios.h>
#include <fcntl.h>

typedef struct {
	struct termios tty;
	int width;
	int height;
	int is_init;
} readline_info_t;

#endif
