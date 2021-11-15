#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = Polygon;
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

void RenderArea::setShape(Shape shape){
    this->shape = shape;
    update();
}

void RenderArea::mousePressEvent(QMouseEvent *event){
    board.handleClickEvent(event);
    this->update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    board.drawBoard(&painter, width(), height());
}
