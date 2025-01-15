#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "Board.h"

void displayLoop(Board b, WINDOW *win, Move current_move);
void drawSquare(const int x, const int y, const int l, const int c, WINDOW *win);
void drawBoard(WINDOW *win); 
void drawPieces(Board, WINDOW *win);
void drawCurrentMove(Move m, WINDOW *win);

#endif
