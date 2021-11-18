#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop: public Piece
{
public:
    Bishop (Coord coord, Color color);
    std::vector<Coord> getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces) override;
};

#endif // BISHOP_H
