#include "private.h"

static int x = 0;
static int y = 0;
static int width = 1;

char **screen = NULL;
int screen_height = 0;
char *prompt = "";

int rdl_init_screen(int width) {
	
}

void rdl_redisplay() {
	if (y)
		dprintf("\e[%dA", y);
	if (x)
		dprintf("\e[%dD", x);
	dprintf("\e[0j");
	for (int i = 0; i < screen_height; i++) {
		if (i == screen_height - 1)
			dprintf("%s", screen[i]);
		else
			dprintf("%s\r\n", screen[i]);
	}
	dprintf("%
}
