#include "MainWindow.h"
#include "RectangleWidget.h"
#include "MovableWidget.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 200));

//    RectangleWidget* rect = new RectangleWidget(this);
//    rect->setFixedSize(10, 20);
//    rect->setColor(QColor(255,0,0,255));
//    rect->setStyleSheet("border:1px solid black; border-right:0px;");

//    rect->setStyleSheet("border:1px solid black; ");
//    rect->setStyleSheet("background:#FF9D3B; border:1px solid black; ");
//    rect->setStyleSheet("border-right:0px;");

    QWidget* lineWidget = new QWidget(this);
    lineWidget->setGeometry(QRect(80, 40, 400, 100));
    lineWidget->setStyleSheet("border:1px solid black;");
    QHBoxLayout* lineWidgetLayout = new QHBoxLayout(lineWidget);

    MovableWidget* moveWidget = new MovableWidget(this);
    QHBoxLayout* moveWidgetLayout = new QHBoxLayout(this);
    moveWidget->setLayout(moveWidgetLayout);

    for (auto i =0; i < 10; i++)
    {
        RectangleWidget* rect = new RectangleWidget(this);
        rect->setMinimumSize(40, 60);
        rect->setColor(QColor(255,0,0,255));

        if (i != 9)
            rect->setStyleSheet("border:1px solid black; border-right:0px;");
        else
            rect->setStyleSheet("border:1px solid black;");

        moveWidgetLayout->addWidget(rect);
    }

    lineWidgetLayout->addWidget(moveWidget);
    lineWidget->setLayout(lineWidgetLayout);

}

MainWindow::~MainWindow()
{
}

