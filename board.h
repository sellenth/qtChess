#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QMouseEvent>
#include <QPainter>
#include <piece.h>
#include <pawn.h>
#include <bishop.h>
#include <knight.h>
#include <king.h>
#include <queen.h>
#include <rook.h>
#include <player.h>
#include <humanplayer.h>


class Board
{
public:
    Board();
    void drawBoard(QPainter* painter, int rWidth, int rHeight);
    void drawGrid();
    void drawActiveCells();
    void drawPieces();
    void handleClickEvent(QMouseEvent *event);
    Player* p1;
    Player* p2;
    Player* currPlayer;
    std::vector<Coord> activeCells;

    std::vector<std::unique_ptr<Piece>> pieces;

private:
    void parseFEN(std::string fenString);
    int gridSideLength;
    int gridPadding;
    QPainter* mPainter;
};

#endif // BOARD_H
