#ifndef ROOK_H
#define ROOK_H

#include <piece.h>

class Rook: public Piece
{
public:
    Rook (Coord coord, Color color);
    std::vector<Coord> getLegalMoves() override;
};

#endif // ROOK_H
