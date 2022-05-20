#include "Path.h"

Path::Path(QWidget *parent)
    : QWidget{parent},
      m_lineThickness{1}
{}

void Path::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));

    QPainterPath path;
    path.moveTo(0, 0);

    path.quadTo(width()-m_lineThickness, 0, width()-m_lineThickness, width()-m_lineThickness);

    path.quadTo(width()-m_lineThickness, height(), 0, height());

    painter.drawPath(path);
}
