#include "humanplayer.h"

humanPlayer::humanPlayer(std::string pName)
{
    name = pName;
    canCastleKingSide = false;
    canCastleQueenSide = false;
}

Coord humanPlayer::makeMove()
{
    return (Coord){File::A, 1};
}
