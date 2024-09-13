#ifndef __CHINESE_CT_H__
#define __CHINESE_CT_H__

#include <stdbool.h>

#define WIDTH 9
#define LENTH 10

typedef enum Player { Black = 0, Red = 1, Empty } Player;

typedef enum ChessType {
    CT_No = 0, // 无

    /** for black player */
    CT_B_B, // 卒
    CT_B_P, // 炮
    CT_B_C, // 车
    CT_B_M, // 马
    CT_B_X, // 象
    CT_B_S, // 士
    CT_B_J, // 将

    /** for red player */
    CT_R_B, // 兵
    CT_R_P, // 炮
    CT_R_C, // 车
    CT_R_M, // 马
    CT_R_X, // 相
    CT_R_S, // 士
    CT_R_J, // 帅

    CT_CNT
} ChessType;

typedef struct Cord {
    int x, y;
} Cord;

typedef ChessType Board[LENTH][WIDTH];
typedef bool CanMoveBoard[LENTH][WIDTH];

Player getPlayer(ChessType ChessType);

#endif