#include "private.h"
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

//void redisplay(


/*
PLAN:
	update_event -> blocking read
	treat_event
		if ev == '\n' -> return
	check win size
		if -> redisplay

store
x, y as index
lines as char *, \n (if real \n)
*/
void terminal_get_size(int *w, int *h) {
	struct winsize win;
	ioctl(0, TIOCGWINSZ, &win);

	*w = win.ws_col;
	*h = win.ws_row;
}

#define UP 'A'
#define DOWN 'B'
#define RIGHT 'C'
#define LEFT 'D'

static int x = 0;
static int y = 0;
static int width = 1;
static int height = 0;
char *screen = NULL;
int screen_size = 0;

void redisplay() {
	char *screen = readline_info.screen;
int width = readline_info.width;
	int height = readline_info.height;
	int org[2] = {readline_info.org_x, readline_info.org_y};
	int cursor[2] = {readline_info.cx, readline_info.cx};

	if (readline_info.cy - 1)
		dprintf(1, "\e[%dF", readline_info.cy - 1);
	dprintf(1, "\e[0j");
	int off = 0;
	for (int i = 0; i < 3; i++) {
		write(1, &screen[off], strnlen(&screen[off], width));
		dprintf(2, "%d|%d", i, off);
		dprintf(2, "|\n");
		if (i != height -1)
			dprintf(1, "\n\r");
		off += width;
	}
	dprintf(1, "\e[%dA", readline_info.cy - 2);
	//write(2, "START\n", 6);
	//write(2, screen, height * width);
	//write(2, "END--\n", 6);
}

char *readline(char *prompt) {
	terminal_get_size(&readline_info.width, &readline_info.height);
	
	readline_info.cx = 1;
	readline_info.cy = 1;
	//memset(readline_info.screen, 'A', readline_info.width * 2);
	while (1) {
		char c = 0;
		int r = read(1, &c, 1);		
		if (r == 1) {
	//		if (c == 0x0a)
	//			readline_info.cy += 1;
	//		else if (c == '\t')
	//			redisplay();
			//else if (strchr("hjkl", c)) {
			//	char *base = "hjkl";
			//	int idx = (int)(strchr(base, c) - base);
			//	dprintf(1, "idx %d", idx);
			//	move("DBAC"[idx], 1);
			//}
			if (' ' <= c && c <= '~') {
				dprintf(1, "%c", c);
			}
			else
				dprintf(1, "\n%x\n", (unsigned char)c);
		}
		else
			dprintf(1, "Err");
	}
	return NULL;		
}
