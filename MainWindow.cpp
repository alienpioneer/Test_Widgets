#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(QRect(0, 0, 600, 400));

    //ChainWidget* chainWidget = new ChainWidget(30, 20, 60, this);
    //chainWidget->setFixedSize(600,100);

//    QWidget* container = new QWidget();
//    container->setFixedSize(600,100);
//    container->setLayout(new QHBoxLayout());
//    container->layout()->setSpacing(0);
//    container->layout()->setMargin(0);
//    container->layout()->addWidget(chainWidget);

//    QWidget* frameWidget = new QWidget(this);
//    frameWidget->setGeometry(QRect(80, 40, 420, 100));
//    frameWidget->setStyleSheet("border:1px solid black;");
//    frameWidget->setLayout(new QHBoxLayout());
//    frameWidget->layout()->setSpacing(0);
//    frameWidget->layout()->setMargin(0);

//    MovableWidget* moveWidget = new MovableWidget(frameWidget);
//    moveWidget->setFixedSize(620,90);
//    moveWidget->setLayout(new QHBoxLayout());
//    moveWidget->layout()->addWidget(chainWidget);
//    frameWidget->layout()->addWidget(moveWidget);

    //ScrollAreaWidget* area = new ScrollAreaWidget(this, QRect(80, 40, 420, 100));
    //area->addWidget(chainWidget);

    /////////////--------------Overlapping widgets grid layout------------------------///////////////

//    QWidget* m_secondFrameWidget = new QWidget(this);
//    m_secondFrameWidget->setGeometry(QRect(80, 160, 100, 100));
//    m_secondFrameWidget->setStyleSheet("border:1px solid black;");
//    QGridLayout* gridLayout = new QGridLayout(m_secondFrameWidget);
//    gridLayout->setSpacing(0);
//    gridLayout->setMargin(0);
//    m_secondFrameWidget->setLayout(gridLayout);

//    QWidget* w1 = new QWidget();
//    QWidget* w2 = new QWidget();
//    w1->setStyleSheet("border:1px solid black;background-color: rgb(255, 0, 0, 128);");
//    w2->setStyleSheet("border:1px solid black;background-color: blue;");

//    gridLayout->addWidget(w2, 1, 0, 2, 2);
//    gridLayout->addWidget(w1, 0, 0, 2, 2);

    /////////////--------------Overlapping widgets abs position------------------------///////////////

    //QWidget* m_thirdFrameWidget = new QWidget(this);
    //m_thirdFrameWidget->setGeometry(QRect(80, 160, 400, 200));
//    m_thirdFrameWidget->setStyleSheet("border:1px solid black;");

//    QWidget* w3 = new QWidget();
//    QWidget* w4 = new QWidget();
//    w3->setStyleSheet("border:1px solid black;background-color: rgb(255, 0, 0, 128);");
//    w4->setStyleSheet("border:1px solid black;background-color: blue;");

//    w4->setGeometry(50,50,20,20);
//    w4->setParent(m_thirdFrameWidget);
//    w3->setGeometry(40,40,20,20);
//    w3->setParent(m_thirdFrameWidget);


    /////////////--------------Test paths------------------------///////////////

//    Path* ph = new Path(m_thirdFrameWidget);
//    ph->setGeometry(0,1,60,120);

//    SemicircleWidget* semCirc = new SemicircleWidget(m_thirdFrameWidget, 30, true);
//    semCirc->setThickness(2);
//    semCirc->setGeometry(0,0,60,120);

    //RoundedWidget* roundW = new RoundedWidget(m_thirdFrameWidget, 60, 30);
    //roundW ->setGeometry(0,0,400,120);


    /////////////--------------Test Tabs------------------------///////////////

//    QTabWidget* tabW = new QTabWidget(this);
//    tabW ->setGeometry(50,50,500,300);
//    QWidget* testA = new QWidget();
//    testA->setStyleSheet("border:2px solid black;");
//    tabW->addTab(testA, "TabA");
//    QWidget* testB = new QWidget();
//    testB->setStyleSheet("border:1px solid black;");
//    tabW->addTab(testB, "TabB");

    /////////////--------------Test Table View------------------------///////////////

    QWidget* tableWidget = new QWidget(this);
    tableWidget->setLayout(new QHBoxLayout());
    tableWidget->setGeometry(50,50,500,300);
    tableWidget->layout()->setMargin(0);
    tableWidget->layout()->setSpacing(0);

    QTableView* table = new QTableView(this);
//    table->setStyleSheet("QTableView {border: 1px solid #666;gridline-color: #DDD;qproperty-iconSize: 48px 48px;} "\
//                         "QTableView QHeaderView::section:horizontal{ border-left: 1px solid #AAA; border-top:none; } "\
//                         "QTableView QHeaderView::section:horizontal:last  { border-right: none; } "\
//                         "QScrollBar {background-color: #D8D8D8;border:none; } "\
//                         "QScrollBar::handle {border: 1px solid #999;border-bottom-color: #666;border-right-color:#666;border-radius: 4px;"\
//                         "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #E4E4E4, stop:0.5 #D9D9D9, stop:0.501 #D3D3D3 }");

   //table->setStyleSheet("QTableView QHeaderView::section {padding: 0 4px; background-color: #AAA;  border: 1px solid #777;}");
    tableWidget->layout()->addWidget(table);

//    table->setSelectionMode( QAbstractItemView::NoSelection );
//    table->setEditTriggers( QAbstractItemView::NoEditTriggers );

    table->verticalHeader()->hide();
    //table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setSectionsClickable(false);
//    table->horizontalHeader()->setDefaultAlignment( Qt::AlignCenter | Qt::AlignVCenter );
//    table->setSizeAdjustPolicy( QAbstractScrollArea::AdjustToContents );

    TableModel* model = new TableModel(this);
    table->setModel(model);

    // Call these functions directly on the custom the model
    // The table->model() will return an abstract model
    model->setHeaderLabels({"A","B","C","D"}, Qt::Horizontal);
    model->setAltColumnColor(QColor(250,232,122));
    model->useAltColumnColor(true);
    model->useFirstColumnColor(true);

    model->insertRows(0,10, QModelIndex());
    for( int i =0; i < 10; i++ )
    {
        for( int j =0; j < 4; j++ )
        {
            model->setCellData(i,j,QString::number(i));
            //model->setCellColor(i,j,QColor(255,123,124));
        }
    }

    // Set the colors at the beggining
    //model->setFirstColumnColor(QColor(0,255,0));
    //model->setAltColumnColor(QColor(0,0,255));
    //model->useAltColumnColor(false);
    //model->useFirstColumnColor(false);
}

MainWindow::~MainWindow()
{
}
