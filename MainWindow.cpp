#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 400));

    ChainWidget* chainWidget = new ChainWidget(30, 20, 60, this);
    chainWidget->setFixedSize(600,100);

    QWidget* container = new QWidget();
    container->setFixedSize(600,100);
    container->setLayout(new QHBoxLayout());
    container->layout()->setSpacing(0);
    container->layout()->setMargin(0);
    container->layout()->addWidget(chainWidget);

//    QWidget* frameWidget = new QWidget(this);
//    frameWidget->setGeometry(QRect(80, 40, 420, 100));
//    frameWidget->setStyleSheet("border:1px solid black;");
//    frameWidget->setLayout(new QHBoxLayout());
//    frameWidget->layout()->setSpacing(0);
//    frameWidget->layout()->setMargin(0);

//    MovableWidget* moveWidget = new MovableWidget(frameWidget);
//    moveWidget->setFixedSize(620,90);
//    moveWidget->setLayout(new QHBoxLayout());
//    moveWidget->layout()->addWidget(chainWidget);
//    frameWidget->layout()->addWidget(moveWidget);

    ScrollAreaWidget* area = new ScrollAreaWidget(chainWidget, QRect(80, 40, 420, 100));
    area->setParent(this);

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

//    SemicircleWidget* semCirc = new SemicircleWidget(m_thirdFrameWidget, 30, true);
//    semCirc->setThickness(2);
//    semCirc->setGeometry(0,0,60,120);

    RoundedWidget* roundW = new RoundedWidget(m_thirdFrameWidget, 60);
    roundW ->setGeometry(0,0,400,120);
}

MainWindow::~MainWindow()
{
}
