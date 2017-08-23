#include "widget.h"
#include <ctime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    log(QString::fromStdString("application start..."));
    log(QString::fromStdString("init data pool..."));
    dataPool = DataPool::newInstance();
    connect(dataPool,SIGNAL(log(QString)),this,SLOT(log(QString)));

    configure = Configure::newInstance();

    // start the display thread.
    log(QString::fromStdString("start display thread..."));
    displayThread = new DisplayThread();
    connect(displayThread,SIGNAL(display()),this,SLOT(display()));
    displayThread->start();

    log(QString::fromStdString("start collection thread..."));
    collectionThread = new CollectionThread();
    connect(collectionThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
    collectionThread->start();

    connect(ui->pbutton_left,SIGNAL(clicked()),this,SLOT(decreaseCluster()));
    connect(ui->pbutton_right,SIGNAL(clicked()),this,SLOT(increaseCluster()));

}


Widget::~Widget()
{
    delete ui;
    if(displayThread)
    {
        displayThread->stop();
        displayThread->deleteLater();
    }
    if(collectionThread)
    {
        collectionThread->stop();
        collectionThread->deleteLater();
    }
}

void Widget::decreaseCluster()
{
    int currentNum = ui->label_cluster->text().toInt();
    log(QString::fromStdString("current num is ").append(QString::number(currentNum)).append(QString::fromStdString("cluster number is ")).append(QString::number(configure->getClusterNum())));
    if (currentNum > 1){        
        ui->label_cluster->setText(QString::number(currentNum - 1));
    }else{
        ui->label_cluster->setText(QString::number(configure->getClusterNum()));
    }

}

void Widget::increaseCluster()
{
    int currentNum = ui->label_cluster->text().toInt();
    if (currentNum < configure->getClusterNum()){
        ui->label_cluster->setText(QString::number(currentNum + 1));
    }else{
        ui->label_cluster->setText(QString::number(1));
    }

}

void Widget::display()
{
    ui->lcd_pjdy_1->display(dataPool->getDouble("pjdy_1"));
    ui->lcd_pjdy_2->display(dataPool->getDouble("pjdy_2"));
//    ui->lcd_soc->display(dataPool->getDouble("soc"));
//    ui->lcd_zddy_1->display(dataPool->getDouble("zddy_1"));
//    ui->lcd_zddy_2->display(dataPool->getDouble("zddy_2"));
    ui->lcd_zdl->display(dataPool->getDouble("zdl"));
//    ui->lcd_zdwc->display(dataPool->getDouble("zdwc"));
//    ui->lcd_zdwd_1->display(dataPool->getDouble("zdwd_1"));
//    ui->lcd_zdwd_2->display(dataPool->getDouble("zdwd_2"));
    ui->lcd_zdy->display(dataPool->getDouble("zdy"));
//    ui->lcd_zdyc->display(dataPool->getDouble("zdyc"));
//    ui->lcd_zgwd_1->display(dataPool->getDouble("zgwd_1"));
//    ui->lcd_zgwd_2->display(dataPool->getDouble("zgwd_2"));
//    ui->lcd_zxdy_1->display(dataPool->getDouble("zxdy_1"));
//    ui->lcd_zxdy_2->display(dataPool->getDouble("zxdy_2"));
    ui->pBar_soc->setValue(dataPool->getDouble("pBar_soc"));
}
void Widget::log(QString str)
{
    ui->text_log->append(str);
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
