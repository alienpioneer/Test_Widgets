#ifndef ROUNDEDWIDGET_H
#define ROUNDEDWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class RoundedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RoundedWidget(QWidget *parent, int circleWidth, int innerHeight = 0);
    void setThickness(int thickness) { m_lineThickness = thickness; };
    void setLineStyle(Qt::PenStyle style){m_lineStyle = style;};
    void setColor(QColor color){ m_color = color; };
    void setBorderColor(QColor color) { m_borderColor = color; };

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int             m_innerHeight;
    int             m_circleWidth;
    int             m_lineThickness;
    Qt::PenStyle    m_lineStyle;
    QColor          m_color;
    QColor          m_borderColor;
};

#endif // ROUNDEDWIDGET_H
