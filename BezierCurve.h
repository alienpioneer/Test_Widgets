#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QPolygon>
#include <QPainterPath>
#include <QPointF>
#include <QtMath>
#include <QDebug>

class BezierCurve : public QPolygon
{
public:
    BezierCurve();
    void SetRadius(unsigned int iRadius){ m_uiRadius = iRadius; }
    const QPainterPath& GetPath();

private:
    QPointF GetLineStart(int i) const;
    QPointF GetLineEnd(int i) const;
    float GetDistance(QPoint pt1, QPoint pt2) const;

private:
    QPainterPath m_path;
    unsigned int m_uiRadius;
};

#endif // BEZIERCURVE_H
