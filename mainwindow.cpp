#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    renderArea = new RenderArea;

    turnLabel = new QLabel();
    renderArea->label = turnLabel;
    renderArea->updateLabelText();

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setRowStretch(0, 5);
    mainLayout->setColumnStretch(0, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 5);
    mainLayout->addWidget(turnLabel, 1, 0, Qt::AlignCenter);

    QWidget *widget = new QWidget();
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

}
MainWindow::~MainWindow()
{
    delete ui;
}

