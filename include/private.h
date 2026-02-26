#ifndef READLINE_PRIVATE_H
#define READLINE_PRIVATE_H

#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#include <stdint.h>

typedef struct {
	uint16_t *data; // val: &0xff, type >> 8
	size_t len;
	size_t alloc_len;
} buffer_t;

#define CHAR_TYPE(X) ((uint8_t)(X >> 8))
#define CHAR_VAL(X) ((char)x & 0xff)
#define MK_CHAR(X, T) (((uint16_t)x & 0xff) | (((uint16_t)T) << 8))

enum {
	TYPE_CHAR
};

typedef struct {
	struct termios tty;
	int width;
	int height;
	int is_init;
	int old_stdin_flags;
	struct sigaction old_act[7];

	buffer_t stdin_stash;
} readline_info_t;

extern readline_info_t readline_info;

void readline_sig_handler(int sig);

int buffer_append_c(buffer_t *buffer, char c);
int buffer_insert_c(buffer_t *buffer, char c, size_t pos);

#endif
