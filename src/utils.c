#include "private.h"
#include <string.h>
#include <stdlib.h>

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
