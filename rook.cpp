#include "rook.h"


Rook::Rook(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/rook.png")
{
}

Coord Rook::getLegalMoves(){
    return (Coord){A, 1};
}
