#include "queen.h"


Queen::Queen(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/queen.png")
{
}

std::vector<Coord> Queen::getLegalMoves(){
    std::vector<Coord> legalMoves;
}
