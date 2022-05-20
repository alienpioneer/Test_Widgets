#ifndef SEMICIRCLEWIDGET_H
#define SEMICIRCLEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QtMath>

class SemicircleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SemicircleWidget(QWidget *parent = nullptr, int distBetweenCircles = 10);
    void setThickness(int thickness) { m_lineThickness = thickness; };
    void setDistBetweenCircles(int dist) { m_circlesDist = dist; };

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_circlesDist;
    int m_lineThickness;
};

#endif // SEMICIRCLEWIDGET_H
