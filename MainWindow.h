#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "RectangleWidget.h"
#include "MovableWidget.h"
#include "ChainWidget.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onLeftBtnPushed();
    void onRightBtnPushed();

    QScrollArea* m_scrollArea;
    ChainWidget* m_chainWidget;
    QWidget*     m_frameWidget;
    QPushButton* m_leftBtn;
    QPushButton* m_rightBtn;
    QWidget*     m_container;
};
#endif // MAINWINDOW_H
