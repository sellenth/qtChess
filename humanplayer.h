#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <player.h>

class humanPlayer: public Player
{
public:
    humanPlayer(std::string pName, Color color);
    Coord makeMove() override;
};

#endif // HUMANPLAYER_H
