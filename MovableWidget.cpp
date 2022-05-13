#include "MovableWidget.h"
#include <QDebug>

MovableWidget::MovableWidget(QWidget *parent):
    m_isMovable(true)
{
    setParent(parent);
}

void MovableWidget::mousePressEvent(QMouseEvent *event)
{
    m_mousePressOffset = event->pos();
    qDebug() << "MovableWidget pressed";
}

void MovableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isMovable)
        move(mapToParent(event->pos() - m_mousePressOffset));
}
