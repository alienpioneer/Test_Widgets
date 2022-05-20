#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 400));

    ChainWidget* m_chainWidget = new ChainWidget(30, 20, 60, this);
    m_chainWidget->setFixedSize(600,100);

    QWidget* m_frameWidget = new QWidget(this);
    m_frameWidget->setGeometry(QRect(80, 40, 420, 100));
//    frameWidget->setStyleSheet("border:1px solid black;");
    m_frameWidget->setLayout(new QHBoxLayout());
    m_frameWidget->layout()->setSpacing(0);
    m_frameWidget->layout()->setMargin(0);

//    MovableWidget* moveWidget = new MovableWidget(frameWidget);
//    moveWidget->setFixedSize(620,90);
//    moveWidget->setLayout(new QHBoxLayout());
//    moveWidget->layout()->addWidget(chainWidget);
//    frameWidget->layout()->addWidget(moveWidget);

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setGeometry(QRect(80, 40, 420, 100));
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_rightBtn = new QPushButton(this);
    m_rightBtn->setIcon(QIcon(":/move_right"));
    m_rightBtn->setStyleSheet("border: 0px");
    m_rightBtn->setFixedSize(20,100);
    connect(m_rightBtn, &QPushButton::clicked, this, &MainWindow::onLeftBtnPushed);

    m_leftBtn = new QPushButton(this);
    m_leftBtn->setIcon(QIcon(":/move_left"));
    m_leftBtn->setStyleSheet("border: 0px");
    m_leftBtn->setFixedSize(20,100);
    connect(m_leftBtn, &QPushButton::clicked, this, &MainWindow::onRightBtnPushed);
    m_leftBtn->hide();

    QWidget* container = new QWidget();
    container->setLayout(new QHBoxLayout());
    container->layout()->setSpacing(0);
    container->layout()->setMargin(0);
    container->layout()->addWidget(m_chainWidget);

    m_scrollArea->setWidget(container);

    m_frameWidget->layout()->addWidget(m_leftBtn);
    m_frameWidget->layout()->addWidget(m_scrollArea);
    m_frameWidget->layout()->addWidget(m_rightBtn);

    /////////////--------------Overlapping widgets grid layout------------------------///////////////

//    QWidget* m_secondFrameWidget = new QWidget(this);
//    m_secondFrameWidget->setGeometry(QRect(80, 160, 100, 100));
//    m_secondFrameWidget->setStyleSheet("border:1px solid black;");
//    QGridLayout* gridLayout = new QGridLayout(m_secondFrameWidget);
//    gridLayout->setSpacing(0);
//    gridLayout->setMargin(0);
//    m_secondFrameWidget->setLayout(gridLayout);

//    QWidget* w1 = new QWidget();
//    QWidget* w2 = new QWidget();
//    w1->setStyleSheet("border:1px solid black;background-color: rgb(255, 0, 0, 128);");
//    w2->setStyleSheet("border:1px solid black;background-color: blue;");

//    gridLayout->addWidget(w2, 1, 0, 2, 2);
//    gridLayout->addWidget(w1, 0, 0, 2, 2);

    /////////////--------------Overlapping widgets abs position------------------------///////////////

    QWidget* m_thirdFrameWidget = new QWidget(this);
    m_thirdFrameWidget->setGeometry(QRect(80, 160, 400, 200));
//    m_thirdFrameWidget->setStyleSheet("border:1px solid black;");

//    QWidget* w3 = new QWidget();
//    QWidget* w4 = new QWidget();
//    w3->setStyleSheet("border:1px solid black;background-color: rgb(255, 0, 0, 128);");
//    w4->setStyleSheet("border:1px solid black;background-color: blue;");

//    w4->setGeometry(50,50,20,20);
//    w4->setParent(m_thirdFrameWidget);
//    w3->setGeometry(40,40,20,20);
//    w3->setParent(m_thirdFrameWidget);


    /////////////--------------Test paths------------------------///////////////

//    Path* ph = new Path(m_thirdFrameWidget);
//    ph->setGeometry(0,1,60,120);

    SemicircleWidget* semCirc = new SemicircleWidget(m_thirdFrameWidget, 30);
//    semCirc->setThickness(2);
    semCirc->setGeometry(0,0,60,120);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onLeftBtnPushed()
{
    m_scrollArea->horizontalScrollBar()->setValue(m_scrollArea->horizontalScrollBar()->value() + 240);
    m_rightBtn->hide();
    m_leftBtn->show();
}

void MainWindow::onRightBtnPushed()
{
    m_scrollArea->horizontalScrollBar()->setValue(m_scrollArea->horizontalScrollBar()->value() - 240);
    m_leftBtn->hide();
    m_rightBtn->show();
}

