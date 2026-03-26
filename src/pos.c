#include "private.h"

void terminal_get_pos(int *x, int *y) {
	tcflush(0, TCIFLUSH);
	write(1, "\e[6n", 4);
	char c = 0;
	int row = 0;
	int col = 0;
	while (1) {
		read(0, &c, 1);
		if (c != '\e')
			continue;
		read(0, &c, 1);
		if (c != '[')
			continue;
		read(0, &c, 1);
		if (!isdigit(c))
			continue;
		row = 0;
		col = 0;
		while (isdigit(c)) {
			row = row * 10 + c - '0';
			read(0, &c, 1);
		}
		if (c != ';')
			continue;
		read(0, &c, 1);
		if (!isdigit(c))
			continue;
		while (isdigit(c)) {
			col = col * 10 + c - '0';
			read(0, &c, 1);
		}
		if (c != 'R')
			continue;
		break;
	}
	*x = col;
	*y = row;
}
