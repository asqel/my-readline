#include "private.h"

readline_info_t readline_info = {0};

int readline_init() {
	int flags = fcntl(0, F_GETFL, 0);
	if (flags == -1)
		return 1;
	flags |= O_NONBLOCK;
	if (fcntl(0, F_SETFL, flags) == -1)
		return 1;
	return 0;
}
