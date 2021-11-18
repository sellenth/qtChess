#include "pawn.h"


Pawn::Pawn(Coord coord, Color color)
    : Piece(coord, color, PieceType::Pawn, ":/pieces/assets/pawn.png")
    , firstMove(true)
{
}

std::vector<Coord> Pawn::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
    Coord candidateCoord;

    // standard movement
    candidateCoord = { File(mCoord.file), mColor == Black ? mCoord.rank - 1 : mCoord.rank + 1 };
    if (coordInBounds(candidateCoord) && !pieceObstructs(candidateCoord, otherPieces)) {
        legalMoves.push_back(candidateCoord);

        if(firstMove){
            candidateCoord = { File(mCoord.file), mColor == Black ? mCoord.rank - 2 : mCoord.rank + 2 };
            if (coordInBounds(candidateCoord) && !pieceObstructs(candidateCoord, otherPieces)) {
                legalMoves.push_back(candidateCoord);
            }
        }
    }

    // attacking movement
    candidateCoord = { File(mCoord.file - 1), mColor == Black ? mCoord.rank - 1 : mCoord.rank + 1 };
    if (coordInBounds(candidateCoord) && canAttack(candidateCoord, otherPieces)){
        legalMoves.push_back(candidateCoord);
    }

    candidateCoord = { File(mCoord.file + 1), mColor == Black ? mCoord.rank - 1 : mCoord.rank + 1 };
    if (coordInBounds(candidateCoord) && canAttack(candidateCoord, otherPieces)){
        legalMoves.push_back(candidateCoord);
    }

    return legalMoves;
}

void Pawn::moveToCoord(Coord coord){
    Piece::moveToCoord(coord);
    firstMove = false;
}
