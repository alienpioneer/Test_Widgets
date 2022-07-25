#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "RectangleWidget.h"
#include "RoundedWidget.h"
#include "MovableWidget.h"
#include "ChainWidget.h"
#include "SemicircleWidget.h"
#include "ScrollAreaWidget.h"
#include "TableModel.h"
#include <QHeaderView>
#include "Path.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTableView>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
