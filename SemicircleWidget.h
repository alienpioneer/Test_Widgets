#ifndef SEMICIRCLEWIDGET_H
#define SEMICIRCLEWIDGET_H

#include <QWidget>

class SemicircleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SemicircleWidget(QWidget *parent = nullptr, int distBetweenCircles = 1);

};

#endif // SEMICIRCLEWIDGET_H
