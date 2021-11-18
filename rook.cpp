#include "rook.h"


Rook::Rook(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/rook.png")
{

}

std::vector<Coord> Rook::getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces){
    std::vector<Coord> legalMoves;
    Coord candidateCoord;

    // Up movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file), mCoord.rank + i};
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

    // Down movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file), mCoord.rank - i};
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

    // Left movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file - i), mCoord.rank};
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

    // Right movement
    for (int i = 1; i < 8; i++){
        candidateCoord = { File(mCoord.file + i), mCoord.rank};
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
