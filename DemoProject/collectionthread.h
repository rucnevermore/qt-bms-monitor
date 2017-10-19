#ifndef COLLECTIONTHREAD_H
#define COLLECTIONTHREAD_H
#include <QThread>

#define RELEASE
#if defined (RELEASE)
#include "ycapi.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#endif
#include "canparser.h"
#include "cancache.h"

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
#if defined (RELEASE)
    Ycapi *ycapi;
#endif
    CanParser* parser;
    CanCache* cache;
    void sendDebugPackage(unsigned int id, unsigned char length, long long data);
};

#endif // COLLECTIONTHREAD_H
