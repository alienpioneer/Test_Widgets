#ifndef CHAINWIDGET_H
#define CHAINWIDGET_H

#include <QWidget>

class ChainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChainWidget(int nb_links, int elementWidth,int elementHeight, QWidget *parent = nullptr);

signals:

};

#endif // CHAINWIDGET_H
