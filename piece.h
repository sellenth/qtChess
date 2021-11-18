#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <Coord.h>

class Piece
{
public:
    Piece(Coord coord, Color color, PieceType piece, std::string loc);
    Coord mCoord;
    Color mColor;
    PieceType mPiece;
    std::string imgLocation;

    virtual std::vector<Coord> getLegalMoves() = 0;
    bool pieceObstructs(Coord c);
    void moveToCoord(Coord coord);

};

#endif // PIECE_H
