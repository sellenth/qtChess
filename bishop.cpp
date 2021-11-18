#include "bishop.h"


Bishop::Bishop(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/bishop.png")
{
}

std::vector<Coord> Bishop::getLegalMoves(){
    std::vector<Coord> legalMoves;
}
