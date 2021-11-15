#include "piece.h"

Piece::Piece(Coord coord, Color color, PieceType piece, std::string loc)
    : mCoord(coord)
    , mColor(color)
    , mPiece(piece)
    , imgLocation(loc)
{
}
