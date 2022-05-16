#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 200));

    ChainWidget* m_chainWidget = new ChainWidget(30, 20, 60, this);
    m_chainWidget->setFixedSize(600,80);

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

