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
        rect->setColor(QColor(255,0,0,255));
        rect->setId(i);

        if (i != nb_links - 1)
            rect->setStyleSheet("border:1px solid black; border-right:0px;");
        else
            rect->setStyleSheet("border:1px solid black;");

        this->layout()->addWidget(rect);
    }
}
