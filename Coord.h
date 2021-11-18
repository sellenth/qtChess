#ifndef COORD_H
#define COORD_H

enum PieceType {Pawn, Bishop, Knight, King, Queen, Rook};
enum Color {Black, White};
enum File {A, B, C, D, E, F, G, H, MAX};

struct Coord{
    File file;
    int rank;
};

#endif // COORD_H
