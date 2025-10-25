#include "private.h"
#include <stdio.h>

void readline_sig_handler(int sig) {
	printf("received %d\n", sig);
	fflush(stdout);
}
