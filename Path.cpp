#include "Path.h"

Path::Path(QWidget *parent)
    : QWidget{parent}
{

}

void Path::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));

    QPainterPath path;

    path.addRect(0, 0, 120, 120);
    path.moveTo(0, 0);
    path.lineTo(60, 60);

    path.moveTo(0, 0);
    path.quadTo(60,0,60,60);

    path.lineTo(0, 120);

    path.moveTo(60, 60);
    path.quadTo(60,120,0,120);

//    path.addRect(20, 20, 60, 60);
//    path.moveTo(0, 0);
//    path.cubicTo(99, 0,  50, 50,  99, 99);
//    path.cubicTo(0, 99,  50, 50,  0, 0);
//    painter.fillRect(0, 0, 100, 100, Qt::white);
    painter.setBrush(QColor(122, 163, 39));

    painter.drawPath(path);
}
