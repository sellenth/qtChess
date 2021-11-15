#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop: public Piece
{
public:
    Bishop (Coord coord, Color color);
    Coord getLegalMoves() override;
};

#endif // BISHOP_H
