#include "knight.h"


Knight::Knight(Coord coord, Color color)
    : Piece(coord, color, PieceType::Knight, ":/pieces/assets/knight.png")
{
}

Coord Knight::getLegalMoves(){
    return (Coord){A, 1};
}
