#include "king.h"


King::King(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/king.png")
{
}

Coord King::getLegalMoves(){
    return (Coord){A, 1};
}
