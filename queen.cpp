#include "queen.h"


Queen::Queen(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/queen.png")
{
}

std::vector<Coord> Queen::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    // Queen moves are composition of legal rook and bishop moves
    std::vector<Coord> legalSingleAxisMoves, legalDiagonalMoves;

    class Rook psuedoRook(mCoord, mColor);
    class Bishop psuedoBishop(mCoord, mColor);
    legalSingleAxisMoves = psuedoRook.getLegalMoves(otherPieces);
    legalDiagonalMoves = psuedoBishop.getLegalMoves(otherPieces);

    // in order to return a single vector of legal moves (as per function declaration),
    // append the bishop moves to the rook move list and return this joined list
    legalSingleAxisMoves.insert(legalSingleAxisMoves.end(),
                                legalDiagonalMoves.begin(), legalDiagonalMoves.end());
    return legalSingleAxisMoves;
}
