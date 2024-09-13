#include "type.h"

Player getPlayer(ChessType chesstype) {
    if (chesstype >= CT_B_B && chesstype <= CT_B_J)
        return Black;
    else if (chesstype >= CT_R_B && chesstype <= CT_R_J)
        return Red;
    else
        return Empty;
}