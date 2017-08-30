#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <qfile.h>
#include "widget.h"
#include <QGridLayout>

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

    // left layout
    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(w.ui->text_zdy,0,0);
    leftLayout->addWidget(w.ui->lcd_zdy,1,0);
    leftLayout->addWidget(w.ui->text_zdl,2,0);
    leftLayout->addWidget(w.ui->lcd_zdl,3,0);

    // mid layout
    QGridLayout *midLayout = new QGridLayout;
    midLayout->addWidget(w.ui->pBar_soc,0,0);
    midLayout->addWidget(w.ui->text_soc,1,0);
    midLayout->addWidget(w.ui->lcd_soc,1,1);

    // right layout
    QGridLayout *rightLayout = new QGridLayout;
    rightLayout->addWidget(w.ui->text_zdyc,0,0);
    rightLayout->addWidget(w.ui->lcd_zdyc,1,0);
    rightLayout->addWidget(w.ui->text_zdwc,2,0);
    rightLayout->addWidget(w.ui->lcd_zdwc,3,0);

    // body layout
    QGridLayout *bodyLayout = new QGridLayout;

    bodyLayout->setColumnStretch(0,1);
    bodyLayout->setColumnStretch(1,1);
    bodyLayout->setColumnStretch(2,1);
    bodyLayout->setColumnStretch(3,1);
    bodyLayout->setColumnStretch(4,1);
    bodyLayout->setColumnStretch(5,1);
    bodyLayout->setColumnStretch(6,1);
    bodyLayout->setColumnStretch(7,1);
    bodyLayout->setColumnStretch(8,1);

    bodyLayout->addWidget(w.ui->text_zddy,0,0,1,3);
    bodyLayout->addWidget(w.ui->text_zgwd,0,3,1,3);
    bodyLayout->addWidget(w.ui->text_pjdy,0,6,1,3);
    bodyLayout->addWidget(w.ui->label_zddy_loc,1,0);
    bodyLayout->addWidget(w.ui->lcd_zddy_1,1,1);
    bodyLayout->addWidget(w.ui->lcd_zddy_2,1,2);
    bodyLayout->addWidget(w.ui->label_zgwd_loc,1,3);
    bodyLayout->addWidget(w.ui->lcd_zgwd_1,1,4);
    bodyLayout->addWidget(w.ui->lcd_zgwd_2,1,5);
    bodyLayout->addWidget(w.ui->label_pjdy_loc,1,6);
    bodyLayout->addWidget(w.ui->lcd_pjdy_1,1,7);
    bodyLayout->addWidget(w.ui->lcd_pjdy_2,1,8);

    bodyLayout->addWidget(w.ui->text_zxdy,2,0,1,3);
    bodyLayout->addWidget(w.ui->text_zdwd,2,3,1,3);
    bodyLayout->addWidget(w.ui->text_xtzt,2,6,1,3);
    bodyLayout->addWidget(w.ui->label_zxdy_loc,3,0);
    bodyLayout->addWidget(w.ui->lcd_zxdy_1,3,1);
    bodyLayout->addWidget(w.ui->lcd_zxdy_2,3,2);
    bodyLayout->addWidget(w.ui->label_zdwd_loc,3,3);
    bodyLayout->addWidget(w.ui->lcd_zdwd_1,3,4);
    bodyLayout->addWidget(w.ui->lcd_zdwd_2,3,5);
    bodyLayout->addWidget(w.ui->text_value_xtzt,3,6);

    // tail layout
    QGridLayout *tailLayout = new QGridLayout;
    tailLayout->setRowStretch(0,1);
    tailLayout->setRowStretch(1,1);

    tailLayout->addWidget(w.ui->text_c1,0,0);
    tailLayout->addWidget(w.ui->text_c2,0,1);
    tailLayout->addWidget(w.ui->text_c3,0,2);
    tailLayout->addWidget(w.ui->text_c4,0,3);
    tailLayout->addWidget(w.ui->text_c5,0,4);
    tailLayout->addWidget(w.ui->text_c6,0,5);
    tailLayout->addWidget(w.ui->text_c7,0,6);
    tailLayout->addWidget(w.ui->text_c8,0,7);
    tailLayout->addWidget(w.ui->text_c9,0,8);

    tailLayout->addWidget(w.ui->lcd_c1,1,0);
    tailLayout->addWidget(w.ui->lcd_c2,1,1);
    tailLayout->addWidget(w.ui->lcd_c3,1,2);
    tailLayout->addWidget(w.ui->lcd_c4,1,3);
    tailLayout->addWidget(w.ui->lcd_c5,1,4);
    tailLayout->addWidget(w.ui->lcd_c6,1,5);
    tailLayout->addWidget(w.ui->lcd_c7,1,6);
    tailLayout->addWidget(w.ui->lcd_c8,1,7);
    tailLayout->addWidget(w.ui->lcd_c9,1,8);

    // tab layout
    QGridLayout *tabLayout = new QGridLayout;
    tabLayout->setColumnStretch(0,1);
    tabLayout->setColumnStretch(1,1);
    tabLayout->setColumnStretch(2,1);

    tabLayout->setRowStretch(0,1);
    tabLayout->setRowStretch(1,2);
    tabLayout->setRowStretch(2,2);
    tabLayout->setRowStretch(3,1);
    tabLayout->setRowStretch(4,1);

    tabLayout->addWidget(w.ui->label_header,0,1);
    tabLayout->addLayout(leftLayout,1,0);
    tabLayout->addLayout(midLayout,1,1);
    tabLayout->addLayout(rightLayout,1,2);
    tabLayout->addLayout(bodyLayout,2,0,1,3);
    tabLayout->addLayout(tailLayout,3,0,1,3);

    tabLayout->setRowMinimumHeight(4, 25);

    w.ui->tabWidget->setLayout(tabLayout);

    // main layout
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(w.ui->tabWidget);
    w.setLayout(mainLayout);
    w.show();
    return a.exec();
}
