#include "rook.h"


Rook::Rook(Coord coord, Color color)
    : Piece(coord, color, PieceType::Bishop, ":/pieces/assets/rook.png")
{

}
std::vector<Coord> Rook::getLegalMoves(){
    std::vector<Coord> legalMoves;
}
