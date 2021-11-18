#ifndef PAWN_H
#define PAWN_H

#include <piece.h>

class Pawn: public Piece
{
public:
    Pawn(Coord coord, Color color);
    bool firstMove;
    std::vector<Coord> getLegalMoves(std::vector<std::shared_ptr<Piece>>& otherPieces) override;
    void moveToCoord(Coord coord) override;
};

#endif // PAWN_H
