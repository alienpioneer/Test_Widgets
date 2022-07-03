#include "RoundedWidget.h"

RoundedWidget::RoundedWidget(QWidget *parent, int circleWidth, int innerHeight)
    : QWidget{parent},
      m_innerHeight(innerHeight),
      m_lineThickness(1),
      m_lineStyle(Qt::SolidLine),
      m_color(QColor(200,200,200,255)),
      m_borderColor(QColor(0, 0, 0, 255))
{
    m_circleWidth = circleWidth;
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void RoundedWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter( this );
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(m_borderColor, m_lineThickness, m_lineStyle, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(m_color);

    QPainterPath path;
    path.setFillRule(Qt::OddEvenFill);

    path.moveTo( width() - m_circleWidth - m_lineThickness, m_lineThickness );
    path.lineTo(m_circleWidth, m_lineThickness);
    path.quadTo(QPoint( m_lineThickness , m_lineThickness), QPoint(m_lineThickness , height()/2));
    path.quadTo(QPoint(m_lineThickness , height()-m_lineThickness),  QPoint(m_circleWidth, height()-m_lineThickness));
    path.lineTo(width()-m_circleWidth-m_lineThickness, height()-m_lineThickness);
    path.quadTo(QPoint(width()-m_lineThickness, height()-m_lineThickness), QPoint(width()-m_lineThickness, height()/2));
    path.quadTo(QPoint(width()-m_lineThickness, m_lineThickness), QPoint(width()-m_circleWidth-m_lineThickness, m_lineThickness));

    if( m_innerHeight != 0)
    {
        path.moveTo( width() - m_circleWidth, m_innerHeight );
        path.lineTo(m_circleWidth, m_innerHeight);
        path.quadTo(QPoint( m_innerHeight, m_innerHeight), QPoint( m_innerHeight , height()/2));
        path.quadTo(QPoint(m_innerHeight , height() - m_innerHeight),  QPoint(m_circleWidth , height() - m_innerHeight));
        path.lineTo(width()-m_circleWidth, height() - m_innerHeight);
        path.quadTo(QPoint(width() - m_innerHeight, height() - m_innerHeight), QPoint(width() - m_innerHeight, height()/2));
        path.quadTo(QPoint(width() - m_innerHeight, m_innerHeight), QPoint(width()-m_circleWidth, m_innerHeight));
    }

    painter.drawPath(path);
    painter.end();
}
