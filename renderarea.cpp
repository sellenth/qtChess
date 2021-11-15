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

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    board.drawBoard(&painter, width(), height());
    /*
    painter.save();




    const int sideLength = std::min(height() / 8, width() / 8);
    const int padding = width() - height() > 0 ? (width() - height()) / 2 : 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ((i + j) % 2){
                painter.setBrush(Qt::SolidPattern);
            } else {
                painter.setBrush(Qt::NoBrush);
            }
            painter.drawRect(QRect(i * sideLength + padding, j * sideLength, sideLength, sideLength));


            QRectF target(i * sideLength + padding, j * sideLength, sideLength, sideLength);
            QImage image(":/pieces/assets/bishop.png");
            image.invertPixels();
            painter.drawImage(target, image);

        }
    }


    painter.setRenderHint(QPainter::Antialiasing, false);
    */
}
