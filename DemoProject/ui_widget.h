/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Aug 22 02:46:32 2017
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_xtxx;
    QTextBrowser *text_zdy;
    QLCDNumber *lcd_zdy;
    QLCDNumber *lcd_zdl;
    QTextBrowser *text_zdl;
    QLabel *label_header;
    QProgressBar *pBar_soc;
    QTextBrowser *text_soc;
    QLCDNumber *lcd_soc;
    QLCDNumber *lcd_zdyc;
    QTextBrowser *text_zdyc;
    QLCDNumber *lcd_zdwc;
    QTextBrowser *text_zdwc;
    QLCDNumber *lcd_zddy_2;
    QTextBrowser *text_zddy;
    QLCDNumber *lcd_zddy_1;
    QLabel *label_zddy_loc;
    QLabel *label_zxdy_loc;
    QLCDNumber *lcd_zxdy_1;
    QTextBrowser *text_zxdy;
    QLCDNumber *lcd_zxdy_2;
    QLabel *label_zgwd_loc;
    QLCDNumber *lcd_zgwd_1;
    QTextBrowser *text_zdwd;
    QLCDNumber *lcd_zdwd_2;
    QTextBrowser *text_zgwd;
    QLCDNumber *lcd_zgwd_2;
    QLabel *label_zdwd_loc;
    QLCDNumber *lcd_zdwd_1;
    QLabel *label_pjdy_loc;
    QLCDNumber *lcd_pjdy_1;
    QTextBrowser *text_xtzt;
    QTextBrowser *text_pjdy;
    QLCDNumber *lcd_pjdy_2;
    QTextBrowser *text_value_xtzt;
    QTextBrowser *text_c1;
    QLCDNumber *lcd_c1;
    QTextBrowser *text_c2;
    QLCDNumber *lcd_c2;
    QTextBrowser *text_c3;
    QLCDNumber *lcd_c3;
    QTextBrowser *text_c4;
    QLCDNumber *lcd_c4;
    QTextBrowser *text_c5;
    QLCDNumber *lcd_c5;
    QTextBrowser *text_c6;
    QLCDNumber *lcd_c6;
    QTextBrowser *text_c7;
    QLCDNumber *lcd_c7;
    QLCDNumber *lcd_c8;
    QTextBrowser *text_c8;
    QLCDNumber *lcd_c9;
    QTextBrowser *text_c9;
    QWidget *tab_cjbxx;
    QWidget *tab_cxxxx;
    QWidget *tab_gzxx;
    QWidget *tab_xtrz;
    QTextBrowser *text_log;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(657, 476);
        Widget->setAutoFillBackground(false);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 651, 471));
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab_xtxx = new QWidget();
        tab_xtxx->setObjectName(QString::fromUtf8("tab_xtxx"));
        text_zdy = new QTextBrowser(tab_xtxx);
        text_zdy->setObjectName(QString::fromUtf8("text_zdy"));
        text_zdy->setGeometry(QRect(40, 30, 101, 61));
        text_zdy->setAutoFillBackground(true);
        text_zdy->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zdy->setFrameShape(QFrame::Box);
        text_zdy->setFrameShadow(QFrame::Sunken);
        text_zdy->setAcceptRichText(true);
        lcd_zdy = new QLCDNumber(tab_xtxx);
        lcd_zdy->setObjectName(QString::fromUtf8("lcd_zdy"));
        lcd_zdy->setGeometry(QRect(60, 60, 64, 23));
        lcd_zdy->setAutoFillBackground(false);
        lcd_zdy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zdy->setFrameShape(QFrame::NoFrame);
        lcd_zdy->setFrameShadow(QFrame::Raised);
        lcd_zdy->setSmallDecimalPoint(false);
        lcd_zdl = new QLCDNumber(tab_xtxx);
        lcd_zdl->setObjectName(QString::fromUtf8("lcd_zdl"));
        lcd_zdl->setGeometry(QRect(60, 140, 64, 23));
        lcd_zdl->setAutoFillBackground(false);
        lcd_zdl->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zdl->setFrameShape(QFrame::NoFrame);
        lcd_zdl->setFrameShadow(QFrame::Raised);
        lcd_zdl->setSmallDecimalPoint(false);
        text_zdl = new QTextBrowser(tab_xtxx);
        text_zdl->setObjectName(QString::fromUtf8("text_zdl"));
        text_zdl->setGeometry(QRect(40, 110, 101, 61));
        text_zdl->setAutoFillBackground(true);
        text_zdl->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zdl->setFrameShape(QFrame::Box);
        text_zdl->setFrameShadow(QFrame::Sunken);
        text_zdl->setAcceptRichText(true);
        label_header = new QLabel(tab_xtxx);
        label_header->setObjectName(QString::fromUtf8("label_header"));
        label_header->setGeometry(QRect(200, 0, 211, 31));
        pBar_soc = new QProgressBar(tab_xtxx);
        pBar_soc->setObjectName(QString::fromUtf8("pBar_soc"));
        pBar_soc->setGeometry(QRect(220, 40, 171, 51));
        pBar_soc->setValue(24);
        text_soc = new QTextBrowser(tab_xtxx);
        text_soc->setObjectName(QString::fromUtf8("text_soc"));
        text_soc->setGeometry(QRect(240, 110, 61, 31));
        text_soc->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_soc->setFrameShape(QFrame::NoFrame);
        lcd_soc = new QLCDNumber(tab_xtxx);
        lcd_soc->setObjectName(QString::fromUtf8("lcd_soc"));
        lcd_soc->setGeometry(QRect(310, 110, 64, 23));
        lcd_soc->setAutoFillBackground(false);
        lcd_soc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_soc->setFrameShape(QFrame::NoFrame);
        lcd_soc->setFrameShadow(QFrame::Raised);
        lcd_soc->setSmallDecimalPoint(false);
        lcd_zdyc = new QLCDNumber(tab_xtxx);
        lcd_zdyc->setObjectName(QString::fromUtf8("lcd_zdyc"));
        lcd_zdyc->setGeometry(QRect(480, 60, 64, 23));
        lcd_zdyc->setAutoFillBackground(false);
        lcd_zdyc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zdyc->setFrameShape(QFrame::NoFrame);
        lcd_zdyc->setFrameShadow(QFrame::Raised);
        lcd_zdyc->setSmallDecimalPoint(false);
        text_zdyc = new QTextBrowser(tab_xtxx);
        text_zdyc->setObjectName(QString::fromUtf8("text_zdyc"));
        text_zdyc->setGeometry(QRect(460, 30, 101, 61));
        text_zdyc->setAutoFillBackground(true);
        text_zdyc->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zdyc->setFrameShape(QFrame::Box);
        text_zdyc->setFrameShadow(QFrame::Sunken);
        text_zdyc->setAcceptRichText(true);
        lcd_zdwc = new QLCDNumber(tab_xtxx);
        lcd_zdwc->setObjectName(QString::fromUtf8("lcd_zdwc"));
        lcd_zdwc->setGeometry(QRect(480, 140, 64, 23));
        lcd_zdwc->setAutoFillBackground(false);
        lcd_zdwc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zdwc->setFrameShape(QFrame::NoFrame);
        lcd_zdwc->setFrameShadow(QFrame::Raised);
        lcd_zdwc->setSmallDecimalPoint(false);
        text_zdwc = new QTextBrowser(tab_xtxx);
        text_zdwc->setObjectName(QString::fromUtf8("text_zdwc"));
        text_zdwc->setGeometry(QRect(460, 110, 101, 61));
        text_zdwc->setAutoFillBackground(true);
        text_zdwc->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zdwc->setFrameShape(QFrame::Box);
        text_zdwc->setFrameShadow(QFrame::Sunken);
        text_zdwc->setAcceptRichText(true);
        lcd_zddy_2 = new QLCDNumber(tab_xtxx);
        lcd_zddy_2->setObjectName(QString::fromUtf8("lcd_zddy_2"));
        lcd_zddy_2->setGeometry(QRect(143, 230, 51, 21));
        lcd_zddy_2->setAutoFillBackground(false);
        lcd_zddy_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zddy_2->setFrameShape(QFrame::NoFrame);
        lcd_zddy_2->setFrameShadow(QFrame::Raised);
        lcd_zddy_2->setSmallDecimalPoint(false);
        text_zddy = new QTextBrowser(tab_xtxx);
        text_zddy->setObjectName(QString::fromUtf8("text_zddy"));
        text_zddy->setGeometry(QRect(30, 200, 171, 61));
        text_zddy->setAutoFillBackground(true);
        text_zddy->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zddy->setFrameShape(QFrame::Box);
        text_zddy->setFrameShadow(QFrame::Sunken);
        text_zddy->setAcceptRichText(true);
        lcd_zddy_1 = new QLCDNumber(tab_xtxx);
        lcd_zddy_1->setObjectName(QString::fromUtf8("lcd_zddy_1"));
        lcd_zddy_1->setGeometry(QRect(80, 230, 51, 21));
        lcd_zddy_1->setAutoFillBackground(false);
        lcd_zddy_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zddy_1->setFrameShape(QFrame::NoFrame);
        lcd_zddy_1->setFrameShadow(QFrame::Raised);
        lcd_zddy_1->setSmallDecimalPoint(false);
        label_zddy_loc = new QLabel(tab_xtxx);
        label_zddy_loc->setObjectName(QString::fromUtf8("label_zddy_loc"));
        label_zddy_loc->setGeometry(QRect(40, 230, 31, 21));
        label_zxdy_loc = new QLabel(tab_xtxx);
        label_zxdy_loc->setObjectName(QString::fromUtf8("label_zxdy_loc"));
        label_zxdy_loc->setGeometry(QRect(40, 300, 31, 21));
        lcd_zxdy_1 = new QLCDNumber(tab_xtxx);
        lcd_zxdy_1->setObjectName(QString::fromUtf8("lcd_zxdy_1"));
        lcd_zxdy_1->setGeometry(QRect(80, 300, 51, 21));
        lcd_zxdy_1->setAutoFillBackground(false);
        lcd_zxdy_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zxdy_1->setFrameShape(QFrame::NoFrame);
        lcd_zxdy_1->setFrameShadow(QFrame::Raised);
        lcd_zxdy_1->setSmallDecimalPoint(false);
        text_zxdy = new QTextBrowser(tab_xtxx);
        text_zxdy->setObjectName(QString::fromUtf8("text_zxdy"));
        text_zxdy->setGeometry(QRect(30, 270, 171, 61));
        text_zxdy->setAutoFillBackground(true);
        text_zxdy->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zxdy->setFrameShape(QFrame::Box);
        text_zxdy->setFrameShadow(QFrame::Sunken);
        text_zxdy->setAcceptRichText(true);
        lcd_zxdy_2 = new QLCDNumber(tab_xtxx);
        lcd_zxdy_2->setObjectName(QString::fromUtf8("lcd_zxdy_2"));
        lcd_zxdy_2->setGeometry(QRect(143, 300, 51, 21));
        lcd_zxdy_2->setAutoFillBackground(false);
        lcd_zxdy_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zxdy_2->setFrameShape(QFrame::NoFrame);
        lcd_zxdy_2->setFrameShadow(QFrame::Raised);
        lcd_zxdy_2->setSmallDecimalPoint(false);
        label_zgwd_loc = new QLabel(tab_xtxx);
        label_zgwd_loc->setObjectName(QString::fromUtf8("label_zgwd_loc"));
        label_zgwd_loc->setGeometry(QRect(240, 230, 31, 21));
        lcd_zgwd_1 = new QLCDNumber(tab_xtxx);
        lcd_zgwd_1->setObjectName(QString::fromUtf8("lcd_zgwd_1"));
        lcd_zgwd_1->setGeometry(QRect(280, 230, 51, 21));
        lcd_zgwd_1->setAutoFillBackground(false);
        lcd_zgwd_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zgwd_1->setFrameShape(QFrame::NoFrame);
        lcd_zgwd_1->setFrameShadow(QFrame::Raised);
        lcd_zgwd_1->setSmallDecimalPoint(false);
        text_zdwd = new QTextBrowser(tab_xtxx);
        text_zdwd->setObjectName(QString::fromUtf8("text_zdwd"));
        text_zdwd->setGeometry(QRect(230, 270, 171, 61));
        text_zdwd->setAutoFillBackground(true);
        text_zdwd->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zdwd->setFrameShape(QFrame::Box);
        text_zdwd->setFrameShadow(QFrame::Sunken);
        text_zdwd->setAcceptRichText(true);
        lcd_zdwd_2 = new QLCDNumber(tab_xtxx);
        lcd_zdwd_2->setObjectName(QString::fromUtf8("lcd_zdwd_2"));
        lcd_zdwd_2->setGeometry(QRect(343, 300, 51, 21));
        lcd_zdwd_2->setAutoFillBackground(false);
        lcd_zdwd_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zdwd_2->setFrameShape(QFrame::NoFrame);
        lcd_zdwd_2->setFrameShadow(QFrame::Raised);
        lcd_zdwd_2->setSmallDecimalPoint(false);
        text_zgwd = new QTextBrowser(tab_xtxx);
        text_zgwd->setObjectName(QString::fromUtf8("text_zgwd"));
        text_zgwd->setGeometry(QRect(230, 200, 171, 61));
        text_zgwd->setAutoFillBackground(true);
        text_zgwd->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_zgwd->setFrameShape(QFrame::Box);
        text_zgwd->setFrameShadow(QFrame::Sunken);
        text_zgwd->setAcceptRichText(true);
        lcd_zgwd_2 = new QLCDNumber(tab_xtxx);
        lcd_zgwd_2->setObjectName(QString::fromUtf8("lcd_zgwd_2"));
        lcd_zgwd_2->setGeometry(QRect(343, 230, 51, 21));
        lcd_zgwd_2->setAutoFillBackground(false);
        lcd_zgwd_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zgwd_2->setFrameShape(QFrame::NoFrame);
        lcd_zgwd_2->setFrameShadow(QFrame::Raised);
        lcd_zgwd_2->setSmallDecimalPoint(false);
        label_zdwd_loc = new QLabel(tab_xtxx);
        label_zdwd_loc->setObjectName(QString::fromUtf8("label_zdwd_loc"));
        label_zdwd_loc->setGeometry(QRect(240, 300, 31, 21));
        lcd_zdwd_1 = new QLCDNumber(tab_xtxx);
        lcd_zdwd_1->setObjectName(QString::fromUtf8("lcd_zdwd_1"));
        lcd_zdwd_1->setGeometry(QRect(280, 300, 51, 21));
        lcd_zdwd_1->setAutoFillBackground(false);
        lcd_zdwd_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_zdwd_1->setFrameShape(QFrame::NoFrame);
        lcd_zdwd_1->setFrameShadow(QFrame::Raised);
        lcd_zdwd_1->setSmallDecimalPoint(false);
        label_pjdy_loc = new QLabel(tab_xtxx);
        label_pjdy_loc->setObjectName(QString::fromUtf8("label_pjdy_loc"));
        label_pjdy_loc->setGeometry(QRect(440, 230, 31, 21));
        lcd_pjdy_1 = new QLCDNumber(tab_xtxx);
        lcd_pjdy_1->setObjectName(QString::fromUtf8("lcd_pjdy_1"));
        lcd_pjdy_1->setGeometry(QRect(480, 230, 51, 21));
        lcd_pjdy_1->setAutoFillBackground(false);
        lcd_pjdy_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_pjdy_1->setFrameShape(QFrame::NoFrame);
        lcd_pjdy_1->setFrameShadow(QFrame::Raised);
        lcd_pjdy_1->setSmallDecimalPoint(false);
        text_xtzt = new QTextBrowser(tab_xtxx);
        text_xtzt->setObjectName(QString::fromUtf8("text_xtzt"));
        text_xtzt->setGeometry(QRect(430, 270, 171, 61));
        text_xtzt->setAutoFillBackground(true);
        text_xtzt->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_xtzt->setFrameShape(QFrame::Box);
        text_xtzt->setFrameShadow(QFrame::Sunken);
        text_xtzt->setAcceptRichText(true);
        text_pjdy = new QTextBrowser(tab_xtxx);
        text_pjdy->setObjectName(QString::fromUtf8("text_pjdy"));
        text_pjdy->setGeometry(QRect(430, 200, 171, 61));
        text_pjdy->setAutoFillBackground(true);
        text_pjdy->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        text_pjdy->setFrameShape(QFrame::Box);
        text_pjdy->setFrameShadow(QFrame::Sunken);
        text_pjdy->setAcceptRichText(true);
        lcd_pjdy_2 = new QLCDNumber(tab_xtxx);
        lcd_pjdy_2->setObjectName(QString::fromUtf8("lcd_pjdy_2"));
        lcd_pjdy_2->setGeometry(QRect(543, 230, 51, 21));
        lcd_pjdy_2->setAutoFillBackground(false);
        lcd_pjdy_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_pjdy_2->setFrameShape(QFrame::NoFrame);
        lcd_pjdy_2->setFrameShadow(QFrame::Raised);
        lcd_pjdy_2->setSmallDecimalPoint(false);
        text_value_xtzt = new QTextBrowser(tab_xtxx);
        text_value_xtzt->setObjectName(QString::fromUtf8("text_value_xtzt"));
        text_value_xtzt->setGeometry(QRect(460, 300, 121, 21));
        text_value_xtzt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_c1 = new QTextBrowser(tab_xtxx);
        text_c1->setObjectName(QString::fromUtf8("text_c1"));
        text_c1->setGeometry(QRect(30, 360, 31, 31));
        lcd_c1 = new QLCDNumber(tab_xtxx);
        lcd_c1->setObjectName(QString::fromUtf8("lcd_c1"));
        lcd_c1->setGeometry(QRect(20, 400, 51, 21));
        lcd_c1->setAutoFillBackground(false);
        lcd_c1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c1->setFrameShape(QFrame::NoFrame);
        lcd_c1->setFrameShadow(QFrame::Raised);
        lcd_c1->setSmallDecimalPoint(false);
        text_c2 = new QTextBrowser(tab_xtxx);
        text_c2->setObjectName(QString::fromUtf8("text_c2"));
        text_c2->setGeometry(QRect(100, 360, 31, 31));
        lcd_c2 = new QLCDNumber(tab_xtxx);
        lcd_c2->setObjectName(QString::fromUtf8("lcd_c2"));
        lcd_c2->setGeometry(QRect(90, 400, 51, 21));
        lcd_c2->setAutoFillBackground(false);
        lcd_c2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c2->setFrameShape(QFrame::NoFrame);
        lcd_c2->setFrameShadow(QFrame::Raised);
        lcd_c2->setSmallDecimalPoint(false);
        text_c3 = new QTextBrowser(tab_xtxx);
        text_c3->setObjectName(QString::fromUtf8("text_c3"));
        text_c3->setGeometry(QRect(170, 360, 31, 31));
        lcd_c3 = new QLCDNumber(tab_xtxx);
        lcd_c3->setObjectName(QString::fromUtf8("lcd_c3"));
        lcd_c3->setGeometry(QRect(160, 400, 51, 21));
        lcd_c3->setAutoFillBackground(false);
        lcd_c3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c3->setFrameShape(QFrame::NoFrame);
        lcd_c3->setFrameShadow(QFrame::Raised);
        lcd_c3->setSmallDecimalPoint(false);
        text_c4 = new QTextBrowser(tab_xtxx);
        text_c4->setObjectName(QString::fromUtf8("text_c4"));
        text_c4->setGeometry(QRect(240, 360, 31, 31));
        lcd_c4 = new QLCDNumber(tab_xtxx);
        lcd_c4->setObjectName(QString::fromUtf8("lcd_c4"));
        lcd_c4->setGeometry(QRect(230, 400, 51, 21));
        lcd_c4->setAutoFillBackground(false);
        lcd_c4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c4->setFrameShape(QFrame::NoFrame);
        lcd_c4->setFrameShadow(QFrame::Raised);
        lcd_c4->setSmallDecimalPoint(false);
        text_c5 = new QTextBrowser(tab_xtxx);
        text_c5->setObjectName(QString::fromUtf8("text_c5"));
        text_c5->setGeometry(QRect(310, 360, 31, 31));
        lcd_c5 = new QLCDNumber(tab_xtxx);
        lcd_c5->setObjectName(QString::fromUtf8("lcd_c5"));
        lcd_c5->setGeometry(QRect(300, 400, 51, 21));
        lcd_c5->setAutoFillBackground(false);
        lcd_c5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c5->setFrameShape(QFrame::NoFrame);
        lcd_c5->setFrameShadow(QFrame::Raised);
        lcd_c5->setSmallDecimalPoint(false);
        text_c6 = new QTextBrowser(tab_xtxx);
        text_c6->setObjectName(QString::fromUtf8("text_c6"));
        text_c6->setGeometry(QRect(380, 360, 31, 31));
        lcd_c6 = new QLCDNumber(tab_xtxx);
        lcd_c6->setObjectName(QString::fromUtf8("lcd_c6"));
        lcd_c6->setGeometry(QRect(370, 400, 51, 21));
        lcd_c6->setAutoFillBackground(false);
        lcd_c6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c6->setFrameShape(QFrame::NoFrame);
        lcd_c6->setFrameShadow(QFrame::Raised);
        lcd_c6->setSmallDecimalPoint(false);
        text_c7 = new QTextBrowser(tab_xtxx);
        text_c7->setObjectName(QString::fromUtf8("text_c7"));
        text_c7->setGeometry(QRect(450, 360, 31, 31));
        lcd_c7 = new QLCDNumber(tab_xtxx);
        lcd_c7->setObjectName(QString::fromUtf8("lcd_c7"));
        lcd_c7->setGeometry(QRect(440, 400, 51, 21));
        lcd_c7->setAutoFillBackground(false);
        lcd_c7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c7->setFrameShape(QFrame::NoFrame);
        lcd_c7->setFrameShadow(QFrame::Raised);
        lcd_c7->setSmallDecimalPoint(false);
        lcd_c8 = new QLCDNumber(tab_xtxx);
        lcd_c8->setObjectName(QString::fromUtf8("lcd_c8"));
        lcd_c8->setGeometry(QRect(510, 400, 51, 21));
        lcd_c8->setAutoFillBackground(false);
        lcd_c8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c8->setFrameShape(QFrame::NoFrame);
        lcd_c8->setFrameShadow(QFrame::Raised);
        lcd_c8->setSmallDecimalPoint(false);
        text_c8 = new QTextBrowser(tab_xtxx);
        text_c8->setObjectName(QString::fromUtf8("text_c8"));
        text_c8->setGeometry(QRect(520, 360, 31, 31));
        lcd_c9 = new QLCDNumber(tab_xtxx);
        lcd_c9->setObjectName(QString::fromUtf8("lcd_c9"));
        lcd_c9->setGeometry(QRect(580, 400, 51, 21));
        lcd_c9->setAutoFillBackground(false);
        lcd_c9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcd_c9->setFrameShape(QFrame::NoFrame);
        lcd_c9->setFrameShadow(QFrame::Raised);
        lcd_c9->setSmallDecimalPoint(false);
        text_c9 = new QTextBrowser(tab_xtxx);
        text_c9->setObjectName(QString::fromUtf8("text_c9"));
        text_c9->setGeometry(QRect(590, 360, 31, 31));
        tabWidget->addTab(tab_xtxx, QString());
        tab_cjbxx = new QWidget();
        tab_cjbxx->setObjectName(QString::fromUtf8("tab_cjbxx"));
        tabWidget->addTab(tab_cjbxx, QString());
        tab_cxxxx = new QWidget();
        tab_cxxxx->setObjectName(QString::fromUtf8("tab_cxxxx"));
        tabWidget->addTab(tab_cxxxx, QString());
        tab_gzxx = new QWidget();
        tab_gzxx->setObjectName(QString::fromUtf8("tab_gzxx"));
        tabWidget->addTab(tab_gzxx, QString());
        tab_xtrz = new QWidget();
        tab_xtrz->setObjectName(QString::fromUtf8("tab_xtrz"));
        text_log = new QTextBrowser(tab_xtrz);
        text_log->setObjectName(QString::fromUtf8("text_log"));
        text_log->setGeometry(QRect(20, 20, 611, 401));
        tabWidget->addTab(tab_xtrz, QString());
        QWidget::setTabOrder(tabWidget, text_zdy);

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\347\233\221\346\216\247\347\273\210\347\253\257", 0, QApplication::UnicodeUTF8));
        text_zdy->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'10pt';\">\346\200\273\347\224\265\345\216\213\357\274\210V\357\274\211</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        text_zdl->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\200\273\347\224\265\346\265\201\357\274\210A\357\274\211</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_header->setText(QApplication::translate("Widget", "\351\225\207\346\261\237\347\247\221\344\277\241\345\212\250\345\212\233\347\263\273\347\273\237\350\256\276\350\256\241\347\240\224\347\251\266\346\234\211\351\231\220\345\205\254\345\217\270", 0, QApplication::UnicodeUTF8));
        text_soc->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SOC(%)</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_zdyc->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\345\244\247\345\216\213\345\267\256\357\274\210V\357\274\211</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_zdwc->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\345\244\247\346\270\251\345\267\256\357\274\210V\357\274\211</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_zddy->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\345\244\247\347\224\265\345\216\213</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_zddy_loc->setText(QApplication::translate("Widget", "Loc:", 0, QApplication::UnicodeUTF8));
        label_zxdy_loc->setText(QApplication::translate("Widget", "Loc:", 0, QApplication::UnicodeUTF8));
        text_zxdy->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\345\260\217\347\224\265\345\216\213</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_zgwd_loc->setText(QApplication::translate("Widget", "Loc:", 0, QApplication::UnicodeUTF8));
        text_zdwd->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\344\275\216\346\270\251\345\272\246</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_zgwd->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\351\253\230\346\270\251\345\272\246</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_zdwd_loc->setText(QApplication::translate("Widget", "Loc:", 0, QApplication::UnicodeUTF8));
        label_pjdy_loc->setText(QApplication::translate("Widget", "Loc:", 0, QApplication::UnicodeUTF8));
        text_xtzt->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\263\273\347\273\237\347\212\266\346\200\201</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_pjdy->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\271\263\345\235\207\347\224\265\345\216\213</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c1->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c2->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c3->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c4->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c5->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c6->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">6</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c7->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">7</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c8->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">8</p></body></html>", 0, QApplication::UnicodeUTF8));
        text_c9->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">9</p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_xtxx), QApplication::translate("Widget", "\347\263\273\347\273\237\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_cjbxx), QApplication::translate("Widget", "\347\260\207\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_cxxxx), QApplication::translate("Widget", "\347\260\207\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_gzxx), QApplication::translate("Widget", "\346\225\205\351\232\234\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_xtrz), QApplication::translate("Widget", "\347\263\273\347\273\237\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
