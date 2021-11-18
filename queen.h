#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>

class Queen: public Piece
{
public:
    Queen (Coord coord, Color color);
    std::vector<Coord> getLegalMoves() override;
};

#endif // QUEEN_H
