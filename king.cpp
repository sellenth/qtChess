#include "king.h"


King::King(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/king.png")
{
}

std::vector<Coord> King::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
    Coord candidateCoord;

    // king can move one square in any direction
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){

            // dont let king move to square it resides on
            if (i == 0 && j == 0){
                continue;
            }
            candidateCoord = { File(mCoord.file + i), mCoord.rank + j};
            if (coordInBounds(candidateCoord)){
                if (canAttackOrEmpty(candidateCoord, otherPieces)){
                    legalMoves.push_back(candidateCoord);
                }
            }
        }
    }
    return legalMoves;
}
