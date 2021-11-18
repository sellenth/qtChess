#include "pawn.h"


Pawn::Pawn(Coord coord, Color color)
    : Piece(coord, color, PieceType::Pawn, ":/pieces/assets/pawn.png")
    , firstMove(true)
{
}

std::vector<Coord> Pawn::getLegalMoves(){
    std::vector<Coord> legalMoves;
    if (mColor == Black){
        legalMoves.push_back(Coord{File(mCoord.file), mCoord.rank - 1});
        if(firstMove){
            legalMoves.push_back(Coord{File(mCoord.file), mCoord.rank - 2});
        }
    } else {
        legalMoves.push_back(Coord{File(mCoord.file), mCoord.rank + 1});
        if(firstMove){
            legalMoves.push_back(Coord{File(mCoord.file), mCoord.rank + 2});
        }
    }
    return legalMoves;
}
