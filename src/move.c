#include "move.h"

static bool valid(Cord cord) {
    if (cord.x >= 0 && cord.x <= LENTH - 1 && cord.y >= 0 &&
        cord.y <= WIDTH - 1)
        return true;
    return false;
}

static bool basicCanMove(Cord src, Cord dst, Board board) {

    // Can not move out of the board
    if (valid(dst) == false)
        return false;

    // Can not eat friend
    if (getPlayer(board[dst.x][dst.y]) == getPlayer(board[src.x][src.y]))
        return false;
    return true;
}

static bool canMove_B(Cord src, Cord dst, Board board) {

    if (basicCanMove(src, dst, board) == false) {
        return false;
    }

    if (board[src.x][src.y] == CT_B_B) {
        if (src.x <= 4) {
            return (src.y == dst.y && src.x + 1 == dst.x);
        } else {
            if (dst.x == src.x) {
                return (src.y + 1 == dst.y) || (src.y - 1 == dst.y);
            } else
                return (src.y == dst.y && src.x + 1 == dst.x);
        }
    } else if (board[src.x][src.y] == CT_R_B) {
        if (src.x >= 5) {
            return (src.y == dst.y && src.x - 1 == dst.x);
        } else {
            if (dst.x == src.x) {
                return (src.y + 1 == dst.y) || (src.y - 1 == dst.y);
            } else
                return (src.y == dst.y && src.x - 1 == dst.x);
        }
    }
    return false;
}

void makeCanMoveBoard(Board board, Cord cord, CanMoveBoard canMoveBoard) {

    // Init CanMoveBoard
    for (int i = 0; i < LENTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canMoveBoard[i][j] = false;
        }
    }

    switch (board[cord.x][cord.y]) {
    case CT_R_B:
    case CT_B_B: {
        Cord dst;
        dst = (Cord){cord.x - 1, cord.y};
        canMoveBoard[dst.x][dst.y] = canMove_B(cord, dst, board);
        dst = (Cord){cord.x + 1, cord.y};
        canMoveBoard[dst.x][dst.y] = canMove_B(cord, dst, board);
        dst = (Cord){cord.x, cord.y + 1};
        canMoveBoard[dst.x][dst.y] = canMove_B(cord, dst, board);
        dst = (Cord){cord.x, cord.y - 1};
        canMoveBoard[dst.x][dst.y] = canMove_B(cord, dst, board);
        break;
    }
    }
}