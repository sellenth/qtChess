#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QCoreApplication>
#include <algorithm>
#include <board.h>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape { Polygon, Rect };

    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    void setShape(Shape shape);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Board board;
    Shape shape;

};

#endif // RENDERAREA_H
