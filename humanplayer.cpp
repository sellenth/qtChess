#include "humanplayer.h"

humanPlayer::humanPlayer(std::string pName, Color color)
{
    name = pName;
    canCastleKingSide = false;
    canCastleQueenSide = false;
    teamColor = color;
}

Coord humanPlayer::makeMove()
{
    return (Coord){File::A, 1};
}
