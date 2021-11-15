#include "queen.h"


Queen::Queen(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/queen.png")
{
}

Coord Queen::getLegalMoves(){
    return (Coord){A, 1};
}
