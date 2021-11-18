#include "knight.h"


Knight::Knight(Coord coord, Color color)
    : Piece(coord, color, PieceType::Knight, ":/pieces/assets/knight.png")
{
}

std::vector<Coord> Knight::getLegalMoves(){
    std::vector<Coord> legalMoves;
}
