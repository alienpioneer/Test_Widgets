#ifndef SEMICIRCLEWIDGET_H
#define SEMICIRCLEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class SemicircleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SemicircleWidget(QWidget *parent = nullptr, int distBetweenCircles = 1);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_circlesDist;
    int m_lineThickness;
};

#endif // SEMICIRCLEWIDGET_H
