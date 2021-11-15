#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    renderArea = new RenderArea;
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Polygon"), RenderArea::Polygon);
    shapeComboBox->addItem(tr("Rectangle"), RenderArea::Rect);

    shapeLabel = new QLabel(tr("&Shape:"));
    shapeLabel->setBuddy(shapeComboBox);

    connect(shapeComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::shapeChanged);

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(shapeComboBox, 2, 1);

    QWidget *widget = new QWidget();
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    shapeChanged();

}

void MainWindow::shapeChanged()
{
    const int IdRole = Qt::UserRole;
    RenderArea::Shape shape = RenderArea::Shape(shapeComboBox->itemData(
                shapeComboBox->currentIndex(), IdRole).toInt());
    renderArea->setShape(shape);
}

MainWindow::~MainWindow()
{
    delete ui;
}

