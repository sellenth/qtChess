#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QPainter>
#include <piece.h>
#include <pawn.h>
#include <bishop.h>
#include <knight.h>
#include <king.h>
#include <queen.h>
#include <rook.h>
#include<QDebug>


class Board
{
public:
    Board();
    void drawBoard(QPainter* painter, int rWidth, int rHeight);
    void drawGrid();
    void drawPieces();

    std::vector<std::unique_ptr<Piece>> pieces;

private:
    void parseFEN(std::string fenString);
    int gridSideLength;
    int gridPadding;
    QPainter* mPainter;
};

#endif // BOARD_H
