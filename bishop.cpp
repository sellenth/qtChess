#include "bishop.h"


Bishop::Bishop(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/bishop.png")
{
}

Coord Bishop::getLegalMoves(){
    return (Coord){A, 1};
}
