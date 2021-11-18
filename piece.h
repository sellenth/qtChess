#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <Coord.h>
#include <memory>

class Piece
{
public:
    Piece(Coord coord, Color color, PieceType piece, std::string loc);
    Coord mCoord;
    Color mColor;
    PieceType mPiece;
    std::string imgLocation;

    virtual std::vector<Coord> getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces) = 0;
    bool pieceObstructs(Coord c, std::vector<std::shared_ptr<Piece>>& otherPieces);
    bool canAttack(Coord c, std::vector<std::shared_ptr<Piece>>& otherPieces);
    bool canAttackOrEmpty(Coord c, std::vector<std::shared_ptr<Piece>>& otherPieces);
    virtual void moveToCoord(Coord coord);
    bool coordInBounds(Coord coord);

};

#endif // PIECE_H
