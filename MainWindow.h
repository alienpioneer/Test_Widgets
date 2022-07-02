#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "RectangleWidget.h"
#include "RoundedWidget.h"
#include "MovableWidget.h"
#include "ChainWidget.h"
#include "SemicircleWidget.h"
#include "ScrollAreaWidget.h"
#include "Path.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QGridLayout>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
