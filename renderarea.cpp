#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    board = Board();
    setBackgroundRole(QPalette::Base);
}

RenderArea::~RenderArea(){
    //painter->end();
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

void RenderArea::mousePressEvent(QMouseEvent *event){
    board.handleClickEvent(event);
    updateLabelText();
    this->update();
}

void RenderArea::updateLabelText(){
    label->setText(QString("It's %1's turn").arg(board.currPlayer->teamColor == 0 ? "Black" : "White"));
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    board.drawBoard(&painter, width(), height());
}
