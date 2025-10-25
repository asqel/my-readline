#include "private.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *readline(char *prompt) {
	size_t input_alloc_len = 0;
	size_t input_len = 0;
	char *input = NULL;
	
	buffer_t buffer = (buffer_t){0};
	int pos = 0;
	while (1) { 
		char c = 0;
		int count = read(0, &c, 1);
		if (count == 0)
			break;
		if (count == -1 && errno == EAGAIN)
			continue;
		if (c == 4)
			return NULL;
		if (c == '\e') {
			char code[3] = {0};
			count = read(0, code, 2);
			if (count == 0)
				return NULL;
			if (count < 0)
				continue;
			if (!strcmp(code,  "[C")) {
				if (pos < buffer.len) {
					pos++;
					write(1, &buffer.data[pos - 1], 1);
				}
			}
			else if (!strcmp(code, "[D"))
				if (pos > 0) {
					pos--;
					write(1, "\b", 1);
				}
		}
		else {
			if (c != 0x7f) {
				fprintf(stderr, "len %d pos %d\n", buffer.len, pos);
				buffer_insert_c(&buffer, c, pos++);
			}
			else {
				fprintf(stderr, "pos %d, len %d\n", pos, buffer.len);
				memmove(&buffer.data[pos - 1], &buffer.data[pos], buffer.len - pos);
				buffer.len--;
				for (int i = 0; i < buffer.len - pos + 1; i++)
					write(1, "\b \b", 3);
				pos--;
			}

			write(1, &buffer.data[pos - 1], buffer.len - pos + 1);
			if (buffer.len > pos)
				for (int i = 0; i < buffer.len - pos; i++)
					write(1, "\b", 1);
		}
	}
	return NULL;		
}
