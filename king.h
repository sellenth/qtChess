#ifndef KING_H
#define KING_H

#include <piece.h>

class King: public Piece
{
public:
    King (Coord coord, Color color);
    Coord getLegalMoves() override;
};

#endif // KING_H
