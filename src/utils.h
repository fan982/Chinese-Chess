#ifndef __CHINESE_CHESS_UTIL_H__
#define __CHINESE_CHESS_UTIL_H__

#include "move.h"
#include "type.h"

/** ChessType-related */
char getSymbol(ChessType chesstype);

/** Board-related */
void initBoard(Board board);
void drawBoard(Board board);
int scoreBoard(Board board);
void showMoves(Board board, Cord cord);

#endif