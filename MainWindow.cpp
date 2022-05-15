#include "MainWindow.h"
#include "RectangleWidget.h"
#include "MovableWidget.h"
#include "ChainWidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 200));

    ChainWidget* chainWidget = new ChainWidget(30, 20, 60, this);
    chainWidget->setFixedSize(600,80);

//    QWidget* frameWidget = new QWidget(this);
//    frameWidget->setGeometry(QRect(80, 40, 420, 100));
//    frameWidget->setStyleSheet("border:1px solid black;");
//    frameWidget->setLayout(new QHBoxLayout());

//    MovableWidget* moveWidget = new MovableWidget(frameWidget);
//    moveWidget->setFixedSize(620,90);
//    moveWidget->setLayout(new QHBoxLayout());

//    moveWidget->layout()->addWidget(chainWidget);
//    frameWidget->layout()->addWidget(moveWidget);

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setGeometry(QRect(80, 40, 420, 100));
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setCentralWidget(scrollArea);
//    scrollArea->setWidget(chainWidget);

    QPushButton* btnLeft = new QPushButton(this);
//    btnLeft->setStyleSheet("border: 0px");
    btnLeft->setFixedSize(20,90);
    connect(btnLeft, &QPushButton::clicked, this, &MainWindow::onLeftBtnPushed);

    QPushButton* btnRight = new QPushButton(this);
//    btnRight->setStyleSheet("border: 0px");
    btnRight->setFixedSize(20,90);
    connect(btnRight, &QPushButton::clicked, this, &MainWindow::onRightBtnPushed);

    QWidget* container = new QWidget();

    container->setLayout(new QHBoxLayout());
    container->layout()->setSpacing(0);
    container->layout()->setMargin(0);
//    container->setGeometry(QRect(80, 40, 420, 100));
    container->layout()->addWidget(btnLeft);
    container->layout()->addWidget(chainWidget);
    container->layout()->addWidget(btnRight);

    m_scrollArea->setWidget(container);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onLeftBtnPushed()
{
    m_scrollArea->horizontalScrollBar()->setValue(m_scrollArea->horizontalScrollBar()->value() + 240);
}

void MainWindow::onRightBtnPushed()
{
    m_scrollArea->horizontalScrollBar()->setValue(m_scrollArea->horizontalScrollBar()->value() - 240);
}

