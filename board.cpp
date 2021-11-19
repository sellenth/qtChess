#include "board.h"

Board::Board()
{
    p1 = new humanPlayer("Player 1", White);
    p2 = new humanPlayer("Player 2", Black);
    currPlayer = p1;
    //parseFEN("rnbqkbnr/pppppppp/8/8/8/6p1/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    parseFEN("rnbqkbnr/pppppppp/8/8/4N3/6p1/PPPP1PPP/RNBQKBNR w KQkq - 0 1");
    //parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"); //Standard game start
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

    for (const auto& cell : legalMoves){
        drawActiveCell(cell);
    }

    mPainter->setBrush(QBrush(Qt::black, Qt::NoBrush));
    mPainter->setCompositionMode(QPainter::CompositionMode_SourceOver);
}

void Board::handleClickEvent(QMouseEvent *event){
    legalMoves.clear();

    // Get the cell Coordinates of wherever was just clicked
    int mouseX = (event->position().toPoint().x() - gridPadding) / gridSideLength;
    int mouseY = 7 - (event->position().toPoint().y() / gridSideLength);
    Coord coordClicked = (Coord){File(mouseX), mouseY};

    // If a piece exists on the square (and is one that current player owns)
    // then make it the currently selected piece
    std::shared_ptr<Piece> piece = getPieceAtCoord(coordClicked);
    if (piece != nullptr && selectedPiece != piece){
        selectedPiece = piece;
    }

    // If a piece is selected, get its legal moves.
    if (selectedPiece){
        legalMoves = selectedPiece->getLegalMoves(pieces);

        // if a legal move is selected, move the piece there
        // If the move is an attack, there will be a piece
        // there so remove it that's the case
        if (isLegalMove(coordClicked)){
            removePieceFromCoord(coordClicked);
            selectedPiece->moveToCoord(coordClicked);
            legalMoves.clear();
            if (selectedPiece->shouldPromote()){
                removePieceFromCoord(coordClicked);
                pieces.push_back(std::make_shared<class Queen>(coordClicked, currPlayer->teamColor));
            }
            selectedPiece = nullptr;
            currPlayer == p1 ? currPlayer = p2 : currPlayer = p1;
        }
        //qDebug() << "King is being attacked: " << coordIsAttacked();
    }
}





bool Board::coordIsAttacked(Coord c){
    for (const auto& piece : pieces){
        for (const auto& move : piece->getLegalMoves(pieces)) {
            if (move.file == c.file && move.rank == c.rank){
                return true;
            }
        }
    }
    return false;
}

void Board::removePieceFromCoord(Coord c){
    for (auto it = pieces.begin(); it != pieces.end(); it++){
        auto& piece = *it;
        if (piece->mCoord.file == c.file && piece->mCoord.rank == c.rank){
            pieces.erase(it);
            break;
        }
    }
}

bool Board::isLegalMove(Coord c){
    // If there's no piece selected, there is nothing to move: therefore illegal
    if (selectedPiece == nullptr){
        return false;
    }

    for (const auto& move : legalMoves){
        if (c.file == move.file && c.rank == move.rank){
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
