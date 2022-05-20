#include "SemicircleWidget.h"

SemicircleWidget::SemicircleWidget(QWidget *parent, int distBetweenCircles)
    : QWidget{parent},
      m_circlesDist{distBetweenCircles},
      m_lineThickness{1}
{}

void SemicircleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter* painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));

    QPainterPath path;
    path.moveTo(0, m_lineThickness);
    path.quadTo(width()-m_lineThickness, 0, width()-m_lineThickness, width()-m_lineThickness);
    path.quadTo(width()-m_lineThickness, height()-m_lineThickness, 0, height()-m_lineThickness);

    path.moveTo(0, 0);

    painter->drawPath(path);
}
