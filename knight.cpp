#include "knight.h"


Knight::Knight(Coord coord, Color color)
    : Piece(coord, color, PieceType::Knight, ":/pieces/assets/knight.png")
{
}

std::vector<Coord> Knight::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
    Coord candidateCoord;

    // LongVertical movement
    for (int i = -1; i <= 1; i+=2){
        for (int j = -2; j <= 2; j+=4){
            candidateCoord = { File(mCoord.file + i), mCoord.rank + j};
            if (coordInBounds(candidateCoord) && canAttackOrEmpty(candidateCoord, otherPieces)){
                    legalMoves.push_back(candidateCoord);
            }
        }
    }

    // LongHorizontal movement
    for (int i = -1; i <= 1; i+=2){
        for (int j = -2; j <= 2; j+=4){
            candidateCoord = { File(mCoord.file + j), mCoord.rank + i};
            if (coordInBounds(candidateCoord) && canAttackOrEmpty(candidateCoord, otherPieces)){
                    legalMoves.push_back(candidateCoord);
            }
        }
    }

    return legalMoves;
}
