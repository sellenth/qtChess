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
    void handleClickEvent(QMouseEvent *event);
    std::shared_ptr<Piece> getPieceAtCoord(Coord c);

    Player* p1;
    Player* p2;
    Player* currPlayer;
    std::vector<Coord> activeCells;
    std::vector<std::shared_ptr<Piece>> pieces;
    std::shared_ptr<Piece> selectedPiece;

private:
    void drawGrid();
    void drawActiveCell(Coord c);
    void drawActiveCells();
    void drawPieces();
    void parseFEN(std::string fenString);
    bool isLegalMove(Coord c);
    int gridSideLength;
    int gridPadding;
    QPainter* mPainter;
};

#endif // BOARD_H
