#ifndef SCROLLAREAWIDGET_H
#define SCROLLAREAWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QScroller>
#include <QScrollerProperties>
#include <QHBoxLayout>

class ScrollAreaWidget : public QWidget
{
    Q_OBJECT
public:
    ScrollAreaWidget(QWidget* parent, QRect geometryRect);
    void addWidget(QWidget* mainWidget);

private slots:
    void onLeftBtnPushed();
    void onRightBtnPushed();

private:
    QWidget*        m_mainWidget;
    QPushButton*    m_leftBtn;
    QPushButton*    m_rightBtn;
    QScroller*      m_scroller;
    QScrollArea*    m_scrollArea;
    QWidget*        m_frameWidget;
};

#endif // SCROLLAREAWIDGET_H
