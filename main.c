#include "src/utils.h"

int main() {
    Board board;
    initBoard(board);
    showMoves(board, (Cord){3, 0});
    return 0;
}