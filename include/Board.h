#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

typedef char Piece[2];
typedef char Move[3];
typedef char Square[2];

typedef Piece Board[8][8];

void resetBoard(Board b);
void printBoard(Board b);
void squareToCoord(Square s, int *x, int *y);
void coordToSquare(Square* s, int x, int y);
void setPiece(Board b, int x, int y, char p, char q);
int validMove(Board b, Move m, int moveSize);
Piece* getPiece(Board b, int x, int y);
Move* getMoves(Board b, int x, int y);

#endif
