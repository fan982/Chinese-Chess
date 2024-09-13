#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char getSymbol(ChessType chesstype) {
    static const char symbols[CT_CNT] = {'+', 'B', 'P', 'C', 'M', 'X', 'S', 'J',
                                         'b', 'p', 'c', 'm', 'x', 's', 'j'};
    return symbols[(int)chesstype];
}

void initBoard(Board board) {
    for (int i = 0; i < LENTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = CT_No;
        }
    }

    // Init CT_B
    for (int i = 0; i < WIDTH; i += 2) {
        board[3][i] = CT_B_B;
        board[LENTH - 4][i] = CT_R_B;
    }

    // Init CT_P
    board[2][1] = board[2][WIDTH - 2] = CT_B_P;
    board[LENTH - 3][1] = board[LENTH - 3][WIDTH - 2] = CT_R_P;

    // Init CT_C
    board[0][0] = board[0][WIDTH - 1] = CT_B_C;
    board[LENTH - 1][0] = board[LENTH - 1][WIDTH - 1] = CT_R_C;

    // Init CT_M
    board[0][1] = board[0][WIDTH - 2] = CT_B_M;
    board[LENTH - 1][1] = board[LENTH - 1][WIDTH - 2] = CT_R_M;

    // Init CT_X
    board[0][2] = board[0][WIDTH - 3] = CT_B_X;
    board[LENTH - 1][2] = board[LENTH - 1][WIDTH - 3] = CT_R_X;

    // Init CT_S
    board[0][3] = board[0][WIDTH - 4] = CT_B_S;
    board[LENTH - 1][3] = board[LENTH - 1][WIDTH - 4] = CT_R_S;

    // Init CT_J
    board[0][4] = CT_B_J;
    board[LENTH - 1][4] = CT_R_J;
}

static char boundarySymbol(Cord cord) {
    int i = cord.x;
    int j = cord.y;
    if (i == 0 && j != 0) {
        return '-';
    } else if (i == LENTH - 1 && j != 0) {
        return '-';
    } else if (j == 0 && i != 0) {
        return '|';
    } else if (j == WIDTH - 1 && i != 0) {
        return '|';
    } else if ((i == 4 || i == 5) && (j != 0 && j != WIDTH - 1)) {
        return '-';
    } else {
        return '+';
    }
}

void drawBoard(Board board) {
    for (int i = 0; i < LENTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Player player = getPlayer(board[i][j]);
            char sym = getSymbol(board[i][j]);
            if (sym == '+')
                sym = boundarySymbol((Cord){i, j});
            if (player == Black) {
                printf("%s", "\x1b[33m");
                printf("%c ", sym);
                printf("%s", "\x1b[0m");
            } else if (player == Red) {
                printf("%s", "\x1b[31m");
                printf("%c ", sym);
                printf("%s", "\x1b[0m");
            } else {
                printf("%c ", sym);
            }
        }
        printf("\n");
    }
}

static void drawMoveBoard(Board board, CanMoveBoard cboard) {
    for (int i = 0; i < LENTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (cboard[i][j] == true) {
                printf("%s", "\x1b[32m");
                printf("%c ", '@');
                printf("%s", "\x1b[0m");
            } else {
                Player player = getPlayer(board[i][j]);
                char sym = getSymbol(board[i][j]);
                if (sym == '+')
                    sym = boundarySymbol((Cord){i, j});
                if (player == Black) {
                    printf("%s", "\x1b[33m");
                    printf("%c ", sym);
                    printf("%s", "\x1b[0m");
                } else if (player == Red) {
                    printf("%s", "\x1b[31m");
                    printf("%c ", sym);
                    printf("%s", "\x1b[0m");
                } else {
                    printf("%c ", sym);
                }
            }
        }
        printf("\n");
    }
}

void showMoves(Board board, Cord cord) {
    unsigned long idx = 0;
    CanMoveBoard cboard;
    makeCanMoveBoard(board, cord, cboard);
    while (1) {
        system("clear");
        if (idx++ % 2) {
            drawMoveBoard(board, cboard);
        } else {
            drawBoard(board);
        }
        usleep(500000);
    }
}