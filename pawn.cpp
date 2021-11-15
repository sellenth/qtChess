#include "pawn.h"


Pawn::Pawn(Coord coord, Color color)
    : Piece(coord, color, PieceType::Pawn, ":/pieces/assets/pawn.png")
{
}

Coord Pawn::getLegalMoves(){
    return (Coord){A, 1};
}
