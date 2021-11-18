#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight: public Piece
{
public:
    Knight (Coord coord, Color color);
    std::vector<Coord> getLegalMoves() override;
};

#endif // KNIGHT_H
