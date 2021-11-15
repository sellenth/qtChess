#ifndef ROOK_H
#define ROOK_H

#include <piece.h>

class Rook: public Piece
{
public:
    Rook (Coord coord, Color color);
    Coord getLegalMoves() override;
};

#endif // ROOK_H
