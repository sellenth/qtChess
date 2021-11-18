#ifndef KING_H
#define KING_H

#include <piece.h>

class King: public Piece
{
public:
    King (Coord coord, Color color);
    std::vector<Coord> getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces) override;
};

#endif // KING_H
