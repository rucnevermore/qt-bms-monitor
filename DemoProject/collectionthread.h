#ifndef COLLECTIONTHREAD_H
#define COLLECTIONTHREAD_H
#include <QThread>
#include "ycapi.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>

#ifndef PF_CAN
#define PF_CAN 29
#endif

#ifndef AF_CAN
#define AF_CAN PF_CAN
#endif

class CollectionThread : public QThread
{
    Q_OBJECT
public:
//    CollectionThread(Ycapi * ycapi,QObject *parent = 0);
    CollectionThread(QObject *parent = 0);
signals:
    void log(QString str);
public slots:
    void run();
    void stop();

private:
    bool running;
    std::string getstring(int n);
    Ycapi *ycapi;

};

#endif // COLLECTIONTHREAD_H
