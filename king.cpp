#include "king.h"


King::King(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/king.png")
{
}

std::vector<Coord> King::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
}
