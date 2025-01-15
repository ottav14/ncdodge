#include <ncurses.h>
#include <string.h>

int main() {
	
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
	curs_set(0); //Hide cursor
    keypad(stdscr, TRUE); // Enable keypad mode
	start_color();

    int rows, cols;
    getmaxyx(stdscr, rows, cols);  

    const char *message = "Test Message";

    int start_row = rows / 2;
    int start_col = (cols - strlen(message)) / 2; 

    mvaddstr(start_row, start_col, message);
    refresh();

	char ch;
    while((ch = getch()) != 'q') {
	}

    endwin();

    return 0;
}
