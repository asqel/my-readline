#include "private.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *readline(char *prompt) {
	size_t input_alloc_len = 0;
	size_t input_len = 0;
	char *input = NULL;

	while (1) { 
		char c = 0;
		int count = read(0, &c, 1);
		if (count == 0)
			break;
		if (count == -1 && errno == EAGAIN)
			continue;
		if (count < 0)
			break;
		if (c != 0x1b)
			printf("%02x", (unsigned char)c);
		else
			printf("\b");
		fflush(stdout);
	}
	return NULL;		
}
