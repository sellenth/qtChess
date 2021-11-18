#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>
#include <rook.h>
#include <bishop.h>

class Queen: public Piece
{
public:
    Queen (Coord coord, Color color);
    std::vector<Coord> getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces) override;
};

#endif // QUEEN_H
