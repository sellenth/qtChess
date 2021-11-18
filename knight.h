#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight: public Piece
{
public:
    Knight (Coord coord, Color color);
    std::vector<Coord> getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces) override;
};

#endif // KNIGHT_H
