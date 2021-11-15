#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <renderarea.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void shapeChanged();


private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
};
#endif // MAINWINDOW_H
