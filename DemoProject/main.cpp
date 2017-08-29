#include <QtGui/QApplication>
#include <qfile.h>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss("qss/white.qss");
    qss.open(QFile::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();
    Widget w;
    w.show();
    return a.exec();
}
