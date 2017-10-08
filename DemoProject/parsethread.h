#ifndef PARSETHREAD_H
#define PARSETHREAD_H

#include <QThread>
#include "cancache.h"

class ParseThread : public QThread
{
    Q_OBJECT
public:
    ParseThread();
signals:
    void log(QString str);
public slots:
    void run();
    void stop();
private:
    bool running;
    CanCache* cache;
    CanParser* parser;
};

#endif // PARSETHREAD_H
