#include "ChainWidget.h"
#include "RectangleWidget.h"
#include <QHBoxLayout>

ChainWidget::ChainWidget(int nb_links, int elementWidth,int elementHeight, QWidget *parent )
    : QWidget{parent}
{
   setLayout(new QHBoxLayout(this));
   layout()->setMargin(0);
   layout()->setSpacing(0);

    for (auto i =0; i < nb_links; i++)
    {
        RectangleWidget* rect = new RectangleWidget(this);
//        rect->setMinimumSize(40, 60);
        rect->setFixedSize(elementWidth, elementHeight);
        if (i%2)
            rect->setColor(QColor(255,70,80,255));
        else
            rect->setColor(QColor(122, 163, 39, 255));
        rect->setId(i);
        rect->setText(QString::number(i));

        if (i != nb_links - 1)
            rect->setStyleSheet("border:1px solid black; border-right:0px;");
        else
            rect->setStyleSheet("border:1px solid black;");

        this->layout()->addWidget(rect);
    }
}
