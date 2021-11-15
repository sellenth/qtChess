#include "board.h"

Board::Board()
{
    parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Board::parseFEN(std::string fenString){
    std::vector<std::string> segments;
    int currRank = 7;
    File currFile = A;

    for (size_t i = 0; i < fenString.length(); i++){
        int charAsInt = fenString[i] - '0';
        if (charAsInt > 0 && charAsInt < 10){
            currFile = File(currFile + charAsInt);
        }
        switch (fenString[i]){
        case 'p':
            pieces.push_back(std::make_unique<class Pawn>((Coord){currFile, currRank}, Color::Black));
            currFile = File(currFile + 1);
            break;
        case 'P':
            pieces.push_back(std::make_unique<class Pawn>((Coord){currFile, currRank}, Color::White));
            currFile = File(currFile + 1);
            break;
        case 'b':
            pieces.push_back(std::make_unique<class Bishop>((Coord){currFile, currRank}, Color::Black));
            currFile = File(currFile + 1);
            break;
        case 'B':
            pieces.push_back(std::make_unique<class Bishop>((Coord){currFile, currRank}, Color::White));
            currFile = File(currFile + 1);
            break;
        case 'n':
            pieces.push_back(std::make_unique<class Knight>((Coord){currFile, currRank}, Color::Black));
            currFile = File(currFile + 1);
            break;
        case 'N':
            pieces.push_back(std::make_unique<class Knight>((Coord){currFile, currRank}, Color::White));
            currFile = File(currFile + 1);
            break;
        case 'k':
            pieces.push_back(std::make_unique<class King>((Coord){currFile, currRank}, Color::Black));
            currFile = File(currFile + 1);
            break;
        case 'K':
            pieces.push_back(std::make_unique<class King>((Coord){currFile, currRank}, Color::White));
            currFile = File(currFile + 1);
            break;
        case 'q':
            pieces.push_back(std::make_unique<class Queen>((Coord){currFile, currRank}, Color::Black));
            currFile = File(currFile + 1);
            break;
        case 'Q':
            pieces.push_back(std::make_unique<class Queen>((Coord){currFile, currRank}, Color::White));
            currFile = File(currFile + 1);
            break;
        case 'r':
            pieces.push_back(std::make_unique<class Rook>((Coord){currFile, currRank}, Color::Black));
            currFile = File(currFile + 1);
            break;
        case 'R':
            pieces.push_back(std::make_unique<class Rook>((Coord){currFile, currRank}, Color::White));
            currFile = File(currFile + 1);
            break;
        case '/':
            currRank--;
            currFile = A;
        }
    }
}

void Board::drawGrid(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ((i + j) % 2){
                mPainter->setBrush(Qt::SolidPattern);
            } else {
                mPainter->setBrush(Qt::NoBrush);
            }
            mPainter->drawRect(QRect(i * gridSideLength + gridPadding, j * gridSideLength,
                                    gridSideLength, gridSideLength));
        }
    }
}

void Board::drawPieces(){
    for (const auto& piece : pieces){
        QRect target(piece->mCoord.file * gridSideLength + gridPadding,
                     (7 - piece->mCoord.rank) * gridSideLength,
                     gridSideLength, gridSideLength);
        QImage image(piece->imgLocation.c_str());
        if (piece->mColor == Black){
            image.invertPixels();
        }
        mPainter->drawImage(target, image);
    }

}

void Board::drawBoard(QPainter* painter, int rWidth, int rHeight){
    mPainter = painter;
    gridPadding = rWidth - rHeight > 0 ? (rWidth - rHeight) / 2 : 0;
    gridSideLength = std::min(rHeight / 8, rWidth / 8);

    drawGrid();
    drawPieces();
}
