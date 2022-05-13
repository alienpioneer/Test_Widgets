#include "MainWindow.h"
#include "RectangleWidget.h"
#include "MovableWidget.h"
#include "ChainWidget.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 200));

    QWidget* frameWidget = new QWidget(this);
    frameWidget->setGeometry(QRect(80, 40, 420, 100));
    frameWidget->setStyleSheet("border:1px solid black;");
    frameWidget->setLayout(new QHBoxLayout());

    MovableWidget* moveWidget = new MovableWidget(frameWidget);
    moveWidget->setFixedSize(620,90);
    moveWidget->setLayout(new QHBoxLayout());

    ChainWidget* chainWidget = new ChainWidget(30, 20, 60, this);
    chainWidget->setFixedSize(600,80);
    moveWidget->layout()->addWidget(chainWidget);

    frameWidget->layout()->addWidget(moveWidget);
}

MainWindow::~MainWindow()
{
}

