#include "ScrollAreaWidget.h"

ScrollAreaWidget::ScrollAreaWidget(QWidget* mainWidget, QRect geometryRect)
{
    m_frameWidget = new QWidget(this);
    m_frameWidget->setGeometry(geometryRect);
//    frameWidget->setStyleSheet("border:1px solid black;");
    m_frameWidget->setLayout(new QHBoxLayout());
    m_frameWidget->layout()->setSpacing(0);
    m_frameWidget->layout()->setMargin(0);


    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setGeometry(QRect(80, 40, 420, 100));
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setWidget(mainWidget);

    m_scroller = QScroller::scroller(m_scrollArea);
    QScrollerProperties sp;
    //sp.setScrollMetric( QScrollerProperties::DragStartDistance, 0.001 );
    sp.setScrollMetric( QScrollerProperties::MousePressEventDelay, 0.1);
    sp.setScrollMetric( QScrollerProperties::OvershootDragDistanceFactor, 0.1);
    sp.setScrollMetric( QScrollerProperties::OvershootScrollDistanceFactor, 0.1);
    sp.setScrollMetric( QScrollerProperties::OvershootScrollTime, 0.6);
    sp.setScrollMetric( QScrollerProperties::AxisLockThreshold, 1);
    m_scroller->setScrollerProperties(sp);
    QScroller::grabGesture(m_scrollArea, QScroller::LeftMouseButtonGesture);

    m_rightBtn = new QPushButton(this);
    m_rightBtn->setIcon(QIcon(":/move_right"));
    m_rightBtn->setStyleSheet("border: 0px");
    m_rightBtn->setFixedSize(20,100);
    connect(m_rightBtn, &QPushButton::clicked, this, &ScrollAreaWidget::onLeftBtnPushed);

    m_leftBtn = new QPushButton(this);
    m_leftBtn->setIcon(QIcon(":/move_left"));
    m_leftBtn->setStyleSheet("border: 0px");
    m_leftBtn->setFixedSize(20,100);
    connect(m_leftBtn, &QPushButton::clicked, this, &ScrollAreaWidget::onRightBtnPushed);
    m_leftBtn->hide();

    m_frameWidget->layout()->addWidget(m_leftBtn);
    m_frameWidget->layout()->addWidget(m_scrollArea);
    m_frameWidget->layout()->addWidget(m_rightBtn);
}

void ScrollAreaWidget::onLeftBtnPushed()
{
    m_scrollArea->horizontalScrollBar()->setValue(m_scrollArea->horizontalScrollBar()->value() + 240);
    m_rightBtn->hide();
    m_leftBtn->show();
}

void ScrollAreaWidget::onRightBtnPushed()
{
    m_scrollArea->horizontalScrollBar()->setValue(m_scrollArea->horizontalScrollBar()->value() - 240);
    m_leftBtn->hide();
    m_rightBtn->show();
}
