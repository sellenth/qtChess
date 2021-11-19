#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPainter>
#include <QCoreApplication>
#include <algorithm>
#include <board.h>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void mousePressEvent(QMouseEvent *event) override;
    void updateLabelText();
    QLabel* label;


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Board board;

};

#endif // RENDERAREA_H
