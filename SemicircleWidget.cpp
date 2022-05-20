#include "SemicircleWidget.h"

SemicircleWidget::SemicircleWidget(QWidget *parent, int distBetweenCircles)
    : QWidget{parent},
      m_lineThickness(1)
{
    m_circlesDist = distBetweenCircles;
}

void SemicircleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter* painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QColor(0, 0, 0), m_lineThickness, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));

    int R = width()-m_lineThickness;
    int r = R - m_circlesDist;

    QPoint startA       = QPoint(0          , m_lineThickness);
    QPoint handleAUp    = QPoint(R          , m_lineThickness);
    QPoint midA         = QPoint(R          , height()/2);
    QPoint handleADown  = QPoint(R          , height()-m_lineThickness);
    QPoint endA         = QPoint(0          , height()-m_lineThickness);

    QPoint startB       = QPoint(0          , startA.y() + m_circlesDist);
    QPoint handleBUp    = QPoint(r          , handleAUp.y() + m_circlesDist);
    QPoint midB         = QPoint(r          , midA.y());
    QPoint handleBDown  = QPoint(r          , handleADown.y() - m_circlesDist);
    QPoint endB         = QPoint(0          , endA.y() - m_circlesDist);

    QPainterPath path;
    path.moveTo(startA);
    path.quadTo(handleAUp , midA);
    path.quadTo(handleADown, endA);

    path.moveTo(startB);
    path.quadTo(handleBUp , midB);
    path.quadTo(handleBDown, endB);

//    float angle = -30.0;
//    QPoint A0 = QPoint(0,height()/2);
//    QPoint A1 = QPoint(r*qCos(angle), r*qSin(angle));
//    QPoint A2 = QPoint(R*qCos(qDegreesToRadians(angle)), R*qSin(qDegreesToRadians(angle)));

//    path.moveTo(A0);
//    path.lineTo(A1);

    painter->drawPath(path);
}
