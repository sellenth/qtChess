#include "queen.h"


Queen::Queen(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/queen.png")
{
}

std::vector<Coord> Queen::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalSingleAxisMoves, legalDiagonalMoves;

    class Rook psuedoRook(mCoord, mColor);
    class Bishop psuedoBishop(mCoord, mColor);
    legalSingleAxisMoves = psuedoRook.getLegalMoves(otherPieces);
    legalDiagonalMoves = psuedoBishop.getLegalMoves(otherPieces);

    legalSingleAxisMoves.insert(legalSingleAxisMoves.end(),
                                legalDiagonalMoves.begin(), legalDiagonalMoves.end());
    return legalSingleAxisMoves;
}
