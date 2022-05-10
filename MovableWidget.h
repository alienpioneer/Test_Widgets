#ifndef MOVABLEWIDGET_H
#define MOVABLEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class MovableWidget: public QWidget
{
    Q_OBJECT
public:
    MovableWidget(QWidget* parent);
    bool isMovable() {return m_isMovable;};
    void setMobility(bool mobile) {m_isMovable = mobile;};

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint m_mousePressOffset;
    bool m_isMovable;

};

#endif // MOVABLEWIDGET_H
