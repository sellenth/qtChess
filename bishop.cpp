#include "bishop.h"


Bishop::Bishop(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/bishop.png")
{
}

std::vector<Coord> Bishop::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
    Coord candidateCoord;

    // UpLeft movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file - i), mCoord.rank + i};
        if (coordInBounds(candidateCoord)){
            if (canAttack(candidateCoord, otherPieces)){
                legalMoves.push_back(candidateCoord);
                break;
            }
            if (pieceObstructs(candidateCoord, otherPieces)){
                break;
            } else {
                legalMoves.push_back(candidateCoord);
            }
        }
    }

    // DownLeft movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file - i), mCoord.rank - i};
        if (coordInBounds(candidateCoord)){
            if (canAttack(candidateCoord, otherPieces)){
                legalMoves.push_back(candidateCoord);
                break;
            }
            if (pieceObstructs(candidateCoord, otherPieces)){
                break;
            } else {
                legalMoves.push_back(candidateCoord);
            }
        }
    }

    // UpRight movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file + i), mCoord.rank + i};
        if (coordInBounds(candidateCoord)){
            if (canAttack(candidateCoord, otherPieces)){
                legalMoves.push_back(candidateCoord);
                break;
            }
            if (pieceObstructs(candidateCoord, otherPieces)){
                break;
            } else {
                legalMoves.push_back(candidateCoord);
            }
        }
    }

    // DownRight movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file + i), mCoord.rank - i};
        if (coordInBounds(candidateCoord)){
            if (canAttack(candidateCoord, otherPieces)){
                legalMoves.push_back(candidateCoord);
                break;
            }
            if (pieceObstructs(candidateCoord, otherPieces)){
                break;
            } else {
                legalMoves.push_back(candidateCoord);
            }
        }
    }



    return legalMoves;
}
