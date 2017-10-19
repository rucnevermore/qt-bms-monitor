#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <qfile.h>
#include "widget.h"
#include <QGridLayout>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss("/yctek/app/white.qss");
    qss.open(QFile::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();
    Widget w;
    int width= QApplication::desktop()->width();
    int height= QApplication::desktop()->height();
    w.setFixedSize(width,height);
    w.setWindowFlags(Qt::FramelessWindowHint);

    // display alert
//    QMap<string, QTableWidgetItem*> alertItemMap;
//    alertItemMap.insert("dtgybj", new QTableWidgetItem(QString::fromUtf8("单体过压报警")));
//    alertItemMap.insert("dtqybj", new QTableWidgetItem(QString::fromUtf8("单体欠压报警")));
//    alertItemMap.insert("xtgybj", new QTableWidgetItem(QString::fromUtf8("系统过压报警")));
//    alertItemMap.insert("xtqybj", new QTableWidgetItem(QString::fromUtf8("系统欠压报警")));
//    alertItemMap.insert("xtycbj", new QTableWidgetItem(QString::fromUtf8("系统压差报警")));
//    alertItemMap.insert("xtwcbj", new QTableWidgetItem(QString::fromUtf8("系统温差报警")));
//    alertItemMap.insert("xtgwbj", new QTableWidgetItem(QString::fromUtf8("系统过温报警")));
//    alertItemMap.insert("xtdwbj", new QTableWidgetItem(QString::fromUtf8("系统低温报警")));
//    alertItemMap.insert("fdglbj", new QTableWidgetItem(QString::fromUtf8("放电过流报警")));
//    alertItemMap.insert("cdglbj", new QTableWidgetItem(QString::fromUtf8("充电过流报警")));
//    alertItemMap.insert("socgbj", new QTableWidgetItem(QString::fromUtf8("SOC高报警")));
//    alertItemMap.insert("socdbj", new QTableWidgetItem(QString::fromUtf8("SOC低报警")));
//    alertItemMap.insert("xtjybj", new QTableWidgetItem(QString::fromUtf8("系统绝缘报警")));
//    alertItemMap.insert("jzgwbj", new QTableWidgetItem(QString::fromUtf8("极柱高温报警")));
//    alertItemMap.insert("sjzjgz", new QTableWidgetItem(QString::fromUtf8("数据自检故障")));
//    alertItemMap.insert("yzctxgz", new QTableWidgetItem(QString::fromUtf8("与整车通信故障")));
//    alertItemMap.insert("ybmutxgz", new QTableWidgetItem(QString::fromUtf8("与bmu通信故障")));
//    alertItemMap.insert("ycdjtxgz", new QTableWidgetItem(QString::fromUtf8("充电机通信故障")));
//    alertItemMap.insert("jrgz", new QTableWidgetItem(QString::fromUtf8("加热故障")));
//    alertItemMap.insert("fsgz", new QTableWidgetItem(QString::fromUtf8("风扇故障")));
//    alertItemMap.insert("zzzlgz", new QTableWidgetItem(QString::fromUtf8("主正粘连故障")));
//    alertItemMap.insert("zfzlgz", new QTableWidgetItem(QString::fromUtf8("主负粘连故障")));
//    alertItemMap.insert("ycgz", new QTableWidgetItem(QString::fromUtf8("预充故障")));
//    alertItemMap.insert("dycgqgz", new QTableWidgetItem(QString::fromUtf8("电压传感器故障")));
//    alertItemMap.insert("wdcgqgz", new QTableWidgetItem(QString::fromUtf8("温度传感器故障")));
//    w.setAlertItems(alertItemMap);

    w.ui->tableWidget->setColumnCount(5);
    w.ui->tableWidget->setRowCount(5);
//    w.ui->tableWidget->setItem(0,0,alertItemMap.value("dtgybj"));
//    w.ui->tableWidget->setItem(0,1,alertItemMap.value("dtqybj"));
//    w.ui->tableWidget->setItem(0,2,alertItemMap.value("xtgybj"));
//    w.ui->tableWidget->setItem(0,3,alertItemMap.value("xtqybj"));
//    w.ui->tableWidget->setItem(0,4,alertItemMap.value("xtycbj"));
//    w.ui->tableWidget->setItem(1,0,alertItemMap.value("xtwcbj"));
//    w.ui->tableWidget->setItem(1,1,alertItemMap.value("xtgwbj"));
//    w.ui->tableWidget->setItem(1,2,alertItemMap.value("xtdwbj"));
//    w.ui->tableWidget->setItem(1,3,alertItemMap.value("fdglbj"));
//    w.ui->tableWidget->setItem(1,4,alertItemMap.value("cdglbj"));
//    w.ui->tableWidget->setItem(2,0,alertItemMap.value("socgbj"));
//    w.ui->tableWidget->setItem(2,1,alertItemMap.value("socdbj"));
//    w.ui->tableWidget->setItem(2,2,alertItemMap.value("xtjybj"));
//    w.ui->tableWidget->setItem(2,3,alertItemMap.value("jzgwbj"));
//    w.ui->tableWidget->setItem(2,4,alertItemMap.value("sjzjgz"));
//    w.ui->tableWidget->setItem(3,0,alertItemMap.value("yzctxgz"));
//    w.ui->tableWidget->setItem(3,1,alertItemMap.value("ybmutxgz"));
//    w.ui->tableWidget->setItem(3,2,alertItemMap.value("ycdjtxgz"));
//    w.ui->tableWidget->setItem(3,3,alertItemMap.value("jrgz"));
//    w.ui->tableWidget->setItem(3,4,alertItemMap.value("fsgz"));
//    w.ui->tableWidget->setItem(4,0,alertItemMap.value("zzzlgz"));
//    w.ui->tableWidget->setItem(4,1,alertItemMap.value("zfzlgz"));
//    w.ui->tableWidget->setItem(4,2,alertItemMap.value("ycgz"));
//    w.ui->tableWidget->setItem(4,3,alertItemMap.value("dycgqgz"));
//    w.ui->tableWidget->setItem(4,4,alertItemMap.value("wdcgqgz"));

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
    w.ui->tableWidget->setItem(3,2,new QTableWidgetItem(QString::fromUtf8("充电机通信故障")));
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

    w.ui->tableWidget_dy->setItem(0,0,new QTableWidgetItem(QString::fromUtf8("电压1")));
    w.ui->tableWidget_dy->setItem(0,1,new QTableWidgetItem(QString::fromUtf8("电压2")));
    w.ui->tableWidget_dy->setItem(0,2,new QTableWidgetItem(QString::fromUtf8("电压3")));
    w.ui->tableWidget_dy->setItem(0,3,new QTableWidgetItem(QString::fromUtf8("电压4")));
    w.ui->tableWidget_dy->setItem(1,0,new QTableWidgetItem(QString::fromUtf8("电压5")));
    w.ui->tableWidget_dy->setItem(1,1,new QTableWidgetItem(QString::fromUtf8("电压6")));
    w.ui->tableWidget_dy->setItem(1,2,new QTableWidgetItem(QString::fromUtf8("电压7")));
    w.ui->tableWidget_dy->setItem(1,3,new QTableWidgetItem(QString::fromUtf8("电压8")));
    w.ui->tableWidget_dy->setItem(2,0,new QTableWidgetItem(QString::fromUtf8("电压9")));
    w.ui->tableWidget_dy->setItem(2,1,new QTableWidgetItem(QString::fromUtf8("电压10")));
    w.ui->tableWidget_dy->setItem(2,2,new QTableWidgetItem(QString::fromUtf8("电压11")));
    w.ui->tableWidget_dy->setItem(2,3,new QTableWidgetItem(QString::fromUtf8("电压12")));
    w.ui->tableWidget_dy->setItem(3,0,new QTableWidgetItem(QString::fromUtf8("电压13")));
    w.ui->tableWidget_dy->setItem(3,1,new QTableWidgetItem(QString::fromUtf8("电压14")));
    w.ui->tableWidget_dy->setItem(3,2,new QTableWidgetItem(QString::fromUtf8("电压15")));
    w.ui->tableWidget_dy->setItem(3,3,new QTableWidgetItem(QString::fromUtf8("电压16")));
    w.ui->tableWidget_dy->setItem(4,0,new QTableWidgetItem(QString::fromUtf8("电压17")));
    w.ui->tableWidget_dy->setItem(4,1,new QTableWidgetItem(QString::fromUtf8("电压18")));
    w.ui->tableWidget_dy->setItem(4,2,new QTableWidgetItem(QString::fromUtf8("电压19")));
    w.ui->tableWidget_dy->setItem(4,3,new QTableWidgetItem(QString::fromUtf8("电压20")));
    w.ui->tableWidget_dy->setItem(5,0,new QTableWidgetItem(QString::fromUtf8("电压21")));
    w.ui->tableWidget_dy->setItem(5,1,new QTableWidgetItem(QString::fromUtf8("电压22")));
    w.ui->tableWidget_dy->setItem(5,2,new QTableWidgetItem(QString::fromUtf8("电压23")));
    w.ui->tableWidget_dy->setItem(5,3,new QTableWidgetItem(QString::fromUtf8("电压24")));

    w.ui->tableWidget_dy->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_dy->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_dy->verticalHeader()->setVisible(false);
    w.ui->tableWidget_dy->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_dy->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_dy->horizontalHeader()->setStretchLastSection(true);

    // display the temperature
    w.ui->tableWidget_wd->setColumnCount(2);
    w.ui->tableWidget_wd->setRowCount(4);

    w.ui->tableWidget_wd->setItem(0,0,new QTableWidgetItem(QString::fromUtf8("温度1")));
    w.ui->tableWidget_wd->setItem(0,1,new QTableWidgetItem(QString::fromUtf8("温度2")));
    w.ui->tableWidget_wd->setItem(1,0,new QTableWidgetItem(QString::fromUtf8("温度3")));
    w.ui->tableWidget_wd->setItem(1,1,new QTableWidgetItem(QString::fromUtf8("温度4")));
    w.ui->tableWidget_wd->setItem(2,0,new QTableWidgetItem(QString::fromUtf8("温度5")));
    w.ui->tableWidget_wd->setItem(2,1,new QTableWidgetItem(QString::fromUtf8("温度6")));
    w.ui->tableWidget_wd->setItem(3,0,new QTableWidgetItem(QString::fromUtf8("温度7")));
    w.ui->tableWidget_wd->setItem(3,1,new QTableWidgetItem(QString::fromUtf8("温度8")));

    w.ui->tableWidget_wd->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_wd->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_wd->verticalHeader()->setVisible(false);
    w.ui->tableWidget_wd->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_wd->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_wd->horizontalHeader()->setStretchLastSection(true);

    // remove the third column templately

    /*
    w.ui->tableWidget_2->setColumnCount(3);
    w.ui->tableWidget_2->setRowCount(10);
    w.ui->tableWidget_2->verticalHeader()->setResizeMode(QHeaderView::Stretch);  
    w.ui->tableWidget_2->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_2->verticalHeader()->setVisible(false);
    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(0, QHeaderView::ResizeToContents);// date time
    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(2, QHeaderView::ResizeToContents);// 查看
    w.ui->tableWidget_2->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_2->horizontalHeader()->setStretchLastSection(false);
    */

    w.ui->tableWidget_2->setColumnCount(2);
    w.ui->tableWidget_2->setRowCount(10);
    w.ui->tableWidget_2->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_2->verticalHeader()->setStretchLastSection(true);
    w.ui->tableWidget_2->verticalHeader()->setVisible(false);
    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(0, QHeaderView::ResizeToContents);// date time
//    w.ui->tableWidget_2->horizontalHeader()->setResizeMode(2, QHeaderView::ResizeToContents);// 查看
    w.ui->tableWidget_2->horizontalHeader()->setVisible(false);
    w.ui->tableWidget_2->horizontalHeader()->setStretchLastSection(false);

    w.ui->tabWidget->setCurrentIndex(0);
    w.show();
    return a.exec();
}
