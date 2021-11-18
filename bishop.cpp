#include "bishop.h"


Bishop::Bishop(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/bishop.png")
{
}

std::vector<Coord> Bishop::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
}
