#include "MovableWidget.h"

MovableWidget::MovableWidget(QWidget *parent):
    m_isMovable(true)
{
    setParent(parent);
}

void MovableWidget::mousePressEvent(QMouseEvent *event)
{
    m_mousePressOffset = event->pos();
}

void MovableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isMovable)
        move(mapToParent(event->pos() - m_mousePressOffset));
}
