#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <ui_widget.h>
#include "displaythread.h"
#include "collectionthread.h"
#include <datapool.h>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void display();
    void log(QString str);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;
    DataPool* dataPool;
    DisplayThread *displayThread;
    CollectionThread *collectionThread;
};

#endif // WIDGET_H
