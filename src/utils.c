#include "private.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define BUFF_INC (1024)

int buffer_append_c(buffer_t *buffer, char c) {
	if (!buffer)
		return 0;

	if (buffer->len == buffer->alloc_len) {
		char *new_data = realloc(buffer->data, buffer->alloc_len + BUFF_INC);
		if (!new_data)
			return 1;
		buffer->data = new_data;
		buffer->alloc_len += BUFF_INC;
	}

	buffer->data[buffer->len] = c;
	buffer->len++;
	return 0;
}

int buffer_insert_c(buffer_t *buffer, char c, size_t pos) {
	if (buffer_append_c(buffer, c))
		return 1;
	memmove(&buffer->data[pos + 1], &buffer->data[pos], buffer->len - pos);
	buffer->data[pos] = c;
	return 0;
}

int get_cursor_pos(int x, int y) {
	tcflush(0, TCIFLUSH);
	write(1, "\e[6n", 4);
	
	buffer_t buffer = (buffer_t){0};
	while (1) {
		char c = 0;
		int ret = read(0, &c, 1);
		if (ret == 0)
			break;
		if (ret < 0 && errno == EAGAIN)
			continue;
		if (ret < 0 || c == 'R')
			break;
		if (buffer_append_c(&buffer, c)) {
			free(buffer.data);
			return 1;
		}
	}
	int i = 0;
	while (i < buffer.len && buffer.data[i] != '\e')
		i++;
	i++;
	if (i >= bufifer.len) {
		free(buffer.data);
		return 1;
	}

	return 0;
}
