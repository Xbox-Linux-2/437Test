#include <ncurses.h>
#include "font.h"

extern const unsigned char font[];

void printc(char c) {
	int cx = 0;
	int cy = 0;
	int x, y;
	int pixel;

	if (c=='\n') {
		cx = 0;
		if (++cy>=30) cy = 0;
		return;
	}
	for (y = 0; y < 16; y++) {
		for (x = 0; x < 9; x++) {
			pixel = (font[c*16+y] >> (8-x)) & 1;
			if (pixel) pixel = -1;
				if (pixel == -1) {
					mvprintw(y, x, "%c", c);
				}
				refresh();
		}
	}

	if (++cx>=80) {
		cx = 0;
		if (++cy>=30) cy = 0;
	}
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	clear();

    while (true) {
		int ch = getch();
		if (ch == KEY_BACKSPACE) {
			endwin();
			break;
		} else {
			clear();
			printc(ch);
		}
	}
    return 0;
}