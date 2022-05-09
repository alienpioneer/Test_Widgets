#include "MainWindow.h"
#include "RectangleWidget.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 400));

//    RectangleWidget* rect = new RectangleWidget(this);
//    rect->setFixedSize(10, 20);
//    rect->setColor(QColor(255,0,0,255));
//    rect->setStyleSheet("border:1px solid black; border-right:0px;");

//    rect->setStyleSheet("border:1px solid black; ");
//    rect->setStyleSheet("background:#FF9D3B; border:1px solid black; ");
//    rect->setStyleSheet("border-right:0px;");

    MovableWidget* lineWidget = new MovableWidget(this);
    lineWidget->setGeometry(QRect(40,40,400,100));

    QHBoxLayout* layout = new QHBoxLayout(this);

    for (auto i =0; i < 10; i++)
    {
        RectangleWidget* rect = new RectangleWidget(this);
        rect->setMinimumSize(40, 60);
        rect->setColor(QColor(255,0,0,255));

        if (i != 9)
            rect->setStyleSheet("border:1px solid black; border-right:0px;");
        else
            rect->setStyleSheet("border:1px solid black;");

        layout->addWidget(rect);
    }

    lineWidget->setLayout(layout);

}

MainWindow::~MainWindow()
{
}

