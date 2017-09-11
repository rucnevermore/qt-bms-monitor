#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <qfile.h>
#include "widget.h"
#include <QGridLayout>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss("white.qss");
    qss.open(QFile::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();
    Widget w;
    int width= QApplication::desktop()->width();
    int height= QApplication::desktop()->height();
    w.setFixedSize(width,height);
    w.setWindowFlags(Qt::FramelessWindowHint);
//
//    // left layout
//    QGridLayout *leftLayout = new QGridLayout;
//    leftLayout->addWidget(w.ui->text_zdy,0,0);
//    leftLayout->addWidget(w.ui->lcd_zdy,1,0);
//    leftLayout->addWidget(w.ui->text_zdl,2,0);
//    leftLayout->addWidget(w.ui->lcd_zdl,3,0);
//    leftLayout->setContentsMargins(50,50,50,50);
//
//    // mid layout
//    QGridLayout *midLayout = new QGridLayout;
//    midLayout->addWidget(w.ui->pBar_soc,0,0,1,2);
//    midLayout->addWidget(w.ui->text_soc,1,0);
//    midLayout->addWidget(w.ui->lcd_soc,1,1);
//
//    // right layout
//    QGridLayout *rightLayout = new QGridLayout;
//    rightLayout->addWidget(w.ui->text_zdyc,0,0);
//    rightLayout->addWidget(w.ui->lcd_zdyc,1,0);
//    rightLayout->addWidget(w.ui->text_zdwc,2,0);
//    rightLayout->addWidget(w.ui->lcd_zdwc,3,0);
//
//    // body layout
//    QGridLayout *bodyLayout = new QGridLayout;
//
//    bodyLayout->setColumnStretch(0,1);
//    bodyLayout->setColumnStretch(1,1);
//    bodyLayout->setColumnStretch(2,1);
//    bodyLayout->setColumnStretch(3,1);
//    bodyLayout->setColumnStretch(4,1);
//    bodyLayout->setColumnStretch(5,1);
//    bodyLayout->setColumnStretch(6,1);
//    bodyLayout->setColumnStretch(7,1);
//    bodyLayout->setColumnStretch(8,1);
//
//    bodyLayout->addWidget(w.ui->text_zddy,0,0,1,3);
//    bodyLayout->addWidget(w.ui->text_zgwd,0,3,1,3);
//    bodyLayout->addWidget(w.ui->text_pjdy,0,6,1,3);
//    bodyLayout->addWidget(w.ui->label_zddy_loc,1,0);
//    bodyLayout->addWidget(w.ui->lcd_zddy_1,1,1);
//    bodyLayout->addWidget(w.ui->lcd_zddy_2,1,2);
//    bodyLayout->addWidget(w.ui->label_zgwd_loc,1,3);
//    bodyLayout->addWidget(w.ui->lcd_zgwd_1,1,4);
//    bodyLayout->addWidget(w.ui->lcd_zgwd_2,1,5);
//    bodyLayout->addWidget(w.ui->label_pjdy_loc,1,6);
//    bodyLayout->addWidget(w.ui->lcd_pjdy_1,1,7);
//    bodyLayout->addWidget(w.ui->lcd_pjdy_2,1,8);
//
//    bodyLayout->addWidget(w.ui->text_zxdy,2,0,1,3);
//    bodyLayout->addWidget(w.ui->text_zdwd,2,3,1,3);
//    bodyLayout->addWidget(w.ui->text_xtzt,2,6,1,3);
//    bodyLayout->addWidget(w.ui->label_zxdy_loc,3,0);
//    bodyLayout->addWidget(w.ui->lcd_zxdy_1,3,1);
//    bodyLayout->addWidget(w.ui->lcd_zxdy_2,3,2);
//    bodyLayout->addWidget(w.ui->label_zdwd_loc,3,3);
//    bodyLayout->addWidget(w.ui->lcd_zdwd_1,3,4);
//    bodyLayout->addWidget(w.ui->lcd_zdwd_2,3,5);
//    bodyLayout->addWidget(w.ui->text_value_xtzt,3,6);
//
//    // tail layout
//    QGridLayout *tailLayout = new QGridLayout;
//    tailLayout->setRowStretch(0,1);
//    tailLayout->setRowStretch(1,1);
//
//    tailLayout->addWidget(w.ui->text_c1,0,0);
//    tailLayout->addWidget(w.ui->text_c2,0,1);
//    tailLayout->addWidget(w.ui->text_c3,0,2);
//    tailLayout->addWidget(w.ui->text_c4,0,3);
//    tailLayout->addWidget(w.ui->text_c5,0,4);
//    tailLayout->addWidget(w.ui->text_c6,0,5);
//    tailLayout->addWidget(w.ui->text_c7,0,6);
//    tailLayout->addWidget(w.ui->text_c8,0,7);
//    tailLayout->addWidget(w.ui->text_c9,0,8);
//
//    tailLayout->addWidget(w.ui->lcd_c1,1,0);
//    tailLayout->addWidget(w.ui->lcd_c2,1,1);
//    tailLayout->addWidget(w.ui->lcd_c3,1,2);
//    tailLayout->addWidget(w.ui->lcd_c4,1,3);
//    tailLayout->addWidget(w.ui->lcd_c5,1,4);
//    tailLayout->addWidget(w.ui->lcd_c6,1,5);
//    tailLayout->addWidget(w.ui->lcd_c7,1,6);
//    tailLayout->addWidget(w.ui->lcd_c8,1,7);
//    tailLayout->addWidget(w.ui->lcd_c9,1,8);
//
//    tailLayout->setHorizontalSpacing(20);
//    tailLayout->setVerticalSpacing(20);
//
//    // tab layout
//    QGridLayout *tabLayout = new QGridLayout;
//    tabLayout->setColumnStretch(0,1);
//    tabLayout->setColumnStretch(1,1);
//    tabLayout->setColumnStretch(2,1);
//
//    tabLayout->setRowStretch(0,1);
//    tabLayout->setRowStretch(1,2);
//    tabLayout->setRowStretch(2,2);
//    tabLayout->setRowStretch(3,1);
//    tabLayout->setRowStretch(4,1);
//
//    tabLayout->addWidget(w.ui->label_header,0,1);
//    tabLayout->addLayout(leftLayout,1,0);
//    tabLayout->addLayout(midLayout,1,1);
//    tabLayout->addLayout(rightLayout,1,2);
//    tabLayout->addLayout(bodyLayout,2,0,1,3);
//    tabLayout->addLayout(tailLayout,3,0,1,3);
//
//    tabLayout->setRowMinimumHeight(4, 30);
//
//    w.ui->tabWidget->setLayout(tabLayout);
//
//    // main layout
//    QGridLayout *mainLayout = new QGridLayout;
//    mainLayout->addWidget(w.ui->tabWidget);
//    w.setLayout(mainLayout);

    // display alert
    w.ui->tableWidget->setColumnCount(5);
    w.ui->tableWidget->setRowCount(5);
    w.ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::fromUtf8("单体过压报警")));
    w.ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::fromUtf8("单体欠压报警")));
    w.ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::fromUtf8("系统过压报警")));
    w.ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::fromUtf8("系统欠压报警")));
    w.ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::fromUtf8("系统压差报警")));
    w.ui->tableWidget->setItem(1,0,new QTableWidgetItem(QString::fromUtf8("系统温差报警")));
    w.ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::fromUtf8("系统过温报警")));
    w.ui->tableWidget->setItem(1,2,new QTableWidgetItem(QString::fromUtf8("系统低温报警")));
    w.ui->tableWidget->setItem(1,3,new QTableWidgetItem(QString::fromUtf8("放电过流报警")));
    w.ui->tableWidget->setItem(1,4,new QTableWidgetItem(QString::fromUtf8("充电过流报警")));
    w.ui->tableWidget->setItem(2,0,new QTableWidgetItem(QString::fromUtf8("SOC高报警")));
    w.ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::fromUtf8("SOC低报警")));
    w.ui->tableWidget->setItem(2,2,new QTableWidgetItem(QString::fromUtf8("系统绝缘报警")));
    w.ui->tableWidget->setItem(2,3,new QTableWidgetItem(QString::fromUtf8("极柱高温报警")));
    w.ui->tableWidget->setItem(2,4,new QTableWidgetItem(QString::fromUtf8("数据自检故障")));
    w.ui->tableWidget->setItem(3,0,new QTableWidgetItem(QString::fromUtf8("与整车通信故障")));
    w.ui->tableWidget->setItem(3,1,new QTableWidgetItem(QString::fromUtf8("与bmu通信故障")));
    w.ui->tableWidget->setItem(3,2,new QTableWidgetItem(QString::fromUtf8("与充电机通信故障")));
    w.ui->tableWidget->setItem(3,3,new QTableWidgetItem(QString::fromUtf8("加热故障")));
    w.ui->tableWidget->setItem(3,4,new QTableWidgetItem(QString::fromUtf8("风扇故障")));
    w.ui->tableWidget->setItem(4,0,new QTableWidgetItem(QString::fromUtf8("主正粘连故障")));
    w.ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString::fromUtf8("主负粘连故障")));
    w.ui->tableWidget->setItem(4,2,new QTableWidgetItem(QString::fromUtf8("预充故障")));
    w.ui->tableWidget->setItem(4,3,new QTableWidgetItem(QString::fromUtf8("电压传感器故障")));
    w.ui->tableWidget->setItem(4,4,new QTableWidgetItem(QString::fromUtf8("温度传感器故障")));

    w.ui->tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget->verticalHeader()->setVisible(false);   
    w.ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget->horizontalHeader()->setVisible(false);
    w.ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // display the voltage
    w.ui->tableWidget_dy->setColumnCount(4);
    w.ui->tableWidget_dy->setRowCount(6);

    w.ui->tableWidget_dy->setItem(0,0,new QTableWidgetItem(QString::fromUtf8("电压1(mv)")));
    w.ui->tableWidget_dy->setItem(0,1,new QTableWidgetItem(QString::fromUtf8("电压2(mv)")));
    w.ui->tableWidget_dy->setItem(0,2,new QTableWidgetItem(QString::fromUtf8("电压3(mv)")));
    w.ui->tableWidget_dy->setItem(0,3,new QTableWidgetItem(QString::fromUtf8("电压4(mv)")));
    w.ui->tableWidget_dy->setItem(1,0,new QTableWidgetItem(QString::fromUtf8("电压5(mv)")));
    w.ui->tableWidget_dy->setItem(1,1,new QTableWidgetItem(QString::fromUtf8("电压6(mv)")));
    w.ui->tableWidget_dy->setItem(1,2,new QTableWidgetItem(QString::fromUtf8("电压7(mv)")));
    w.ui->tableWidget_dy->setItem(1,3,new QTableWidgetItem(QString::fromUtf8("电压8(mv)")));
    w.ui->tableWidget_dy->setItem(2,0,new QTableWidgetItem(QString::fromUtf8("电压9(mv)")));
    w.ui->tableWidget_dy->setItem(2,1,new QTableWidgetItem(QString::fromUtf8("电压10(mv)")));
    w.ui->tableWidget_dy->setItem(2,2,new QTableWidgetItem(QString::fromUtf8("电压11(mv)")));
    w.ui->tableWidget_dy->setItem(2,3,new QTableWidgetItem(QString::fromUtf8("电压12(mv)")));
    w.ui->tableWidget_dy->setItem(3,0,new QTableWidgetItem(QString::fromUtf8("电压13(mv)")));
    w.ui->tableWidget_dy->setItem(3,1,new QTableWidgetItem(QString::fromUtf8("电压14(mv)")));
    w.ui->tableWidget_dy->setItem(3,2,new QTableWidgetItem(QString::fromUtf8("电压15(mv)")));
    w.ui->tableWidget_dy->setItem(3,3,new QTableWidgetItem(QString::fromUtf8("电压16(mv)")));
    w.ui->tableWidget_dy->setItem(4,0,new QTableWidgetItem(QString::fromUtf8("电压17(mv)")));
    w.ui->tableWidget_dy->setItem(4,1,new QTableWidgetItem(QString::fromUtf8("电压18(mv)")));
    w.ui->tableWidget_dy->setItem(4,2,new QTableWidgetItem(QString::fromUtf8("电压19(mv)")));
    w.ui->tableWidget_dy->setItem(4,3,new QTableWidgetItem(QString::fromUtf8("电压20(mv)")));
    w.ui->tableWidget_dy->setItem(5,0,new QTableWidgetItem(QString::fromUtf8("电压21(mv)")));
    w.ui->tableWidget_dy->setItem(5,1,new QTableWidgetItem(QString::fromUtf8("电压22(mv)")));
    w.ui->tableWidget_dy->setItem(5,2,new QTableWidgetItem(QString::fromUtf8("电压23(mv)")));
    w.ui->tableWidget_dy->setItem(5,3,new QTableWidgetItem(QString::fromUtf8("电压24(mv)")));

    w.ui->tableWidget_dy->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_dy->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_dy->verticalHeader()->setVisible(false);
    w.ui->tableWidget_dy->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_dy->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_dy->horizontalHeader()->setStretchLastSection(true);

    // display the temperature
    w.ui->tableWidget_wd->setColumnCount(2);
    w.ui->tableWidget_wd->setRowCount(4);

    w.ui->tableWidget_wd->setItem(0,0,new QTableWidgetItem(QString::fromUtf8("温度1(%)")));
    w.ui->tableWidget_wd->setItem(0,1,new QTableWidgetItem(QString::fromUtf8("温度2(%)")));
    w.ui->tableWidget_wd->setItem(1,0,new QTableWidgetItem(QString::fromUtf8("温度3(%)")));
    w.ui->tableWidget_wd->setItem(1,1,new QTableWidgetItem(QString::fromUtf8("温度4(%)")));
    w.ui->tableWidget_wd->setItem(2,0,new QTableWidgetItem(QString::fromUtf8("温度5(%)")));
    w.ui->tableWidget_wd->setItem(2,1,new QTableWidgetItem(QString::fromUtf8("温度6(%)")));
    w.ui->tableWidget_wd->setItem(3,0,new QTableWidgetItem(QString::fromUtf8("温度7(%)")));
    w.ui->tableWidget_wd->setItem(3,1,new QTableWidgetItem(QString::fromUtf8("温度8(%)")));

    w.ui->tableWidget_wd->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_wd->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_wd->verticalHeader()->setVisible(false);
    w.ui->tableWidget_wd->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_wd->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_wd->horizontalHeader()->setStretchLastSection(true);

    w.ui->tableWidget_2->setColumnCount(3);
    w.ui->tableWidget_2->setRowCount(10);
    w.ui->tableWidget_2->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_2->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_2->verticalHeader()->setVisible(false);
    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_2->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

    w.show();
    return a.exec();
}
