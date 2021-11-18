#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <Coord.h>


class Player
{
public:
    Player();
    Color teamColor;
    std::string name;

    virtual Coord makeMove() = 0;
    bool canCastleKingSide;
    bool canCastleQueenSide;
};

#endif // PLAYER_H
