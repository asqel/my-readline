#include "private.h"

#define BUFFER_INC 256

int buffer_append(buffer_t *buffer, char c) {
	if (buffer->len == buffer->alloc_len) {
		uint8_t *tmp = realloc(buffer->data, sizeof(uint8_t) * (buffer->alloc_len + BUFFER_INC));
		if (!tmp)
			return 1;
		buffer->data = tmp;
		buffer->alloc_len += BUFFER_INC;
	}
	buffer->data[buffer->len++] = c;
	return 0;
}

int buffer_insert(buffer_t *buffer, char c, size_t pos) {
	if (buffer_append(buffer, c))
		return 1;
	memmove(&buffer->data[pos + 1], &buffer->data[pos], buffer->len - pos - 1);
	buffer->data[pos] = c;
	return 0;
}

void buffer_free(buffer_t *buffer) {
	free(buffer->data);
	buffer->len = 0;
	buffer->alloc_len = 0;
}
