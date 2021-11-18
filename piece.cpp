#include "piece.h"

Piece::Piece(Coord coord, Color color, PieceType piece, std::string loc)
    : mCoord(coord)
    , mColor(color)
    , mPiece(piece)
    , imgLocation(loc)
{
}

bool Piece::pieceObstructs(Coord c, std::vector<std::shared_ptr<Piece>>& otherPieces){
    for (const auto& piece : otherPieces){
        if (piece->mCoord.file == c.file && piece->mCoord.rank == c.rank){
            return true;
        }
    }
    return false;
}

bool Piece::canAttack(Coord c, std::vector<std::shared_ptr<Piece>>& otherPieces){
    for (const auto& piece : otherPieces){
        if (piece->mCoord.file == c.file && piece->mCoord.rank == c.rank && piece->mColor != mColor){
            return true;
        }
    }
    return false;
}

bool Piece::shouldPromote(){
    return false;
}

void Piece::moveToCoord(Coord coord){
    mCoord = coord;
}

bool Piece::coordInBounds(Coord coord){
    return coord.file >= 0 && coord.file < File::MAX && coord.rank >= 0 && coord.rank < 8;
}

bool Piece::canAttackOrEmpty(Coord c, std::vector<std::shared_ptr<Piece>>& otherPieces){
    bool attackable = canAttack(c, otherPieces);
    bool isEmpty = !pieceObstructs(c, otherPieces);
    return attackable || isEmpty;
}
