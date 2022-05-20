#ifndef PATH_H
#define PATH_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>

class Path : public QWidget
{
    Q_OBJECT
public:
    explicit Path(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_lineThickness;
};

#endif // PATH_H
