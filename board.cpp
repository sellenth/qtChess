#include "board.h"

Board::Board()
{
    p1 = new humanPlayer("Player 1", White);
    p2 = new humanPlayer("Player 2", Black);
    currPlayer = p1;
    parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Board::parseFEN(std::string fenString){
    int currRank = 7;
    File currFile = A;
    bool piecePlacement = true;

    for (size_t i = 0; i < fenString.length(); i++){
        int charAsInt = fenString[i] - '0';
        if (charAsInt > 0 && charAsInt < 10){
            currFile = File(currFile + charAsInt);
        }
        switch (tolower((int)(fenString[i]))){
        case 'p':
            pieces.push_back(std::make_shared<class Pawn>((Coord){currFile, currRank}, fenString[i] == 'p' ? Color::Black : Color::White));
            currFile = File(currFile + 1);
            break;
        case 'b':
            if (piecePlacement) {
                pieces.push_back(std::make_shared<class Bishop>((Coord){currFile, currRank}, fenString[i] == 'b' ? Color::Black : Color::White));
                currFile = File(currFile + 1);
            } else {
                currPlayer = p2;
            }
            break;
        case 'n':
            pieces.push_back(std::make_shared<class Knight>((Coord){currFile, currRank}, fenString[i] == 'n' ? Color::Black : Color::White));
            currFile = File(currFile + 1);
            break;
        case 'k':
            if (piecePlacement){
                pieces.push_back(std::make_shared<class King>((Coord){currFile, currRank}, fenString[i] == 'k' ? Color::Black : Color::White));
                currFile = File(currFile + 1);
            } else {
                fenString[i] == 'k' ? p2->canCastleKingSide = true : p1->canCastleKingSide = true;
            }
            break;
        case 'q':
            if (piecePlacement){
                pieces.push_back(std::make_shared<class Queen>((Coord){currFile, currRank}, fenString[i] == 'q' ? Color::Black : Color::White));
                currFile = File(currFile + 1);
            } else {
                fenString[i] == 'q' ? p2->canCastleQueenSide = true : p1->canCastleQueenSide = true;
            }
            break;
        case 'r':
            pieces.push_back(std::make_shared<class Rook>((Coord){currFile, currRank}, fenString[i] == 'r' ? Color::Black : Color::White));
            currFile = File(currFile + 1);
            break;
        case 'w':
            if (piecePlacement) {
                currPlayer = p1;
            }
            break;
        case '/':
            currRank--;
            currFile = A;
            break;
        case ' ':
            piecePlacement = false;
            break;
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


void Board::drawActiveCell(Coord c){
    mPainter->drawRect(QRect(c.file * gridSideLength + gridPadding,
                             (7 - c.rank) * gridSideLength,
                             gridSideLength, gridSideLength));
}

void Board::drawActiveCells(){
    mPainter->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    mPainter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    if (selectedPiece){
        drawActiveCell(selectedPiece->mCoord);
    }

    for (const auto& cell : activeCells){
        drawActiveCell(cell);

    }

    mPainter->setBrush(QBrush(Qt::black, Qt::NoBrush));
    mPainter->setCompositionMode(QPainter::CompositionMode_SourceOver);
}

void Board::handleClickEvent(QMouseEvent *event){
    activeCells.clear();

    int mouseX = (event->position().toPoint().x() - gridPadding) / gridSideLength;
    int mouseY = 7 - (event->position().toPoint().y() / gridSideLength);
    Coord coordClicked = (Coord){File(mouseX), mouseY};

    std::shared_ptr<Piece> piece = getPieceAtCoord(coordClicked);
    if (piece != nullptr && selectedPiece != piece){
        selectedPiece = piece;
    }

    for (const auto& legalC : selectedPiece->getLegalMoves()){
        activeCells.push_back(legalC);
    }


    if (isLegalMove(coordClicked)){
        //pass
    }
    qDebug() << mouseX << ' ' << mouseY;
}

bool Board::isLegalMove(Coord c){
    // If there's no piece selected, there is nothing to move: therefore illegal
    if (selectedPiece == nullptr){
        return false;
    }

    for (const auto& legalC : selectedPiece->getLegalMoves()){
        if (c.file == legalC.file && c.rank == legalC.rank){
            return true;
        }
    }

    // if king and enemy pieces attack legal move
    return false;
}


std::shared_ptr<Piece> Board::getPieceAtCoord(Coord c){
    for (size_t i = 0; i < pieces.size(); i++){
        auto& piece = pieces[i];
        if (piece->mCoord.file == c.file
                && piece->mCoord.rank == c.rank
                && piece->mColor == currPlayer->teamColor){
            return pieces.at(i);
        }
    }
    return nullptr;
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
    drawActiveCells();
    drawPieces();
}
