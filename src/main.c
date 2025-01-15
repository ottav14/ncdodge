#include <ncurses.h>
#include <string.h>

#define ARENA_SIZE 5

void attemptMove(int* cursor, int x, int y, int rows, int cols) {

	int ox = cols / 2;
	int oy = rows / 2;
	if(ox - ARENA_SIZE/2 <= x && x <= ox + ARENA_SIZE/2 &&
	   oy - ARENA_SIZE/2 <= y && y <= oy + ARENA_SIZE/2) {
		cursor[0] = x;
		cursor[1] = y;
	}
		
}

void handleInput(char ch, int* cursor, int rows, int cols) {
	
	switch(ch) {
		case 'h':
			attemptMove(cursor, cursor[0]-1, cursor[1], rows, cols);
			break;
		case 'j':
			attemptMove(cursor, cursor[0], cursor[1]+1, rows, cols);
			break;
		case 'k':
			attemptMove(cursor, cursor[0], cursor[1]-1, rows, cols);
			break;
		case 'l':
			attemptMove(cursor, cursor[0]+1, cursor[1], rows, cols);
			break;
	}

}

void drawWalls(int rows, int cols) {
	int center_x = cols / 2;
	int center_y = rows / 2;

	char tb_str[ARENA_SIZE+3];
	memset(tb_str, '*', sizeof(tb_str)-1);
	tb_str[ARENA_SIZE+2] = 0;

	char mid_str[ARENA_SIZE+3];
	memset(mid_str, ' ', sizeof(mid_str)-1);
	mid_str[0] = '*';
	mid_str[ARENA_SIZE+1] = '*';
	mid_str[ARENA_SIZE+2] = 0;

	mvaddstr(center_y - ARENA_SIZE/2 - 1, center_x - ARENA_SIZE/2 - 1, tb_str);
	mvaddstr(center_y + ARENA_SIZE/2 + 1, center_x - ARENA_SIZE/2 - 1, tb_str);

	for(int i=-ARENA_SIZE/2; i<=ARENA_SIZE/2; i++) {
		mvaddstr(center_y + i, center_x - ARENA_SIZE/2 - 1, mid_str);
	}

}

void drawCursor(int* cursor) {
	
	mvaddch(cursor[1], cursor[0], 'o');

}

void drawScreen(int rows, int cols, int* cursor) {
	drawWalls(rows, cols);
	drawCursor(cursor);
	refresh();
}

int main() {
	
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
	curs_set(0); //Hide cursor
    keypad(stdscr, TRUE); // Enable keypad mode
	start_color();

    int rows, cols;
    getmaxyx(stdscr, rows, cols);  

	int cursor[] = {cols / 2, rows / 2};

	drawScreen(rows, cols, cursor);

	char ch;
    while((ch = getch()) != 'q') {


		handleInput(ch, cursor, rows, cols);

		drawScreen(rows, cols, cursor);
	}

    endwin();

    return 0;
}
