#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <qfile.h>
#include "widget.h"

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
    w.show();
    return a.exec();
}
