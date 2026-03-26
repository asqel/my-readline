#ifndef READLINE_PRIVATE_H
#define READLINE_PRIVATE_H

#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>

typedef struct {
	char **lines;
	size_t len;
} lines_t;

typedef struct {
	struct termios old_tty;
	int fd;
} tty_t;

typedef struct {
	uint8_t *data;
	size_t len;
	size_t alloc_len;
} buffer_t;

typedef struct {
	int is_init;
	int width;
	int height;
	char *screen;
	int cx;
	int cy;
	tty_t tty;

	buffer_t stash;
	lines_t lines;
	int new_width;
	int new_height;
	int org_x;
	int org_y;
} readline_info_t;

extern readline_info_t readline_info;

int readline_init();
void readline_exit();

void buffer_free(buffer_t *buffer);
int buffer_insert(buffer_t *buffer, char c, size_t pos);
int buffer_append(buffer_t *buffer, char c);

void terminal_get_pos(int *x, int *y);

#endif
