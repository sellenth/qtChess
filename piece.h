#ifndef PIECE_H
#define PIECE_H

#include <Coord.h>
#include <string>

class Piece
{
public:
    Piece(Coord coord, Color color, PieceType piece, std::string loc);
    Coord mCoord;
    Color mColor;
    PieceType mPiece;
    std::string imgLocation;

    virtual Coord getLegalMoves() = 0;
    void moveToCoord(Coord coord);

};

#endif // PIECE_H
