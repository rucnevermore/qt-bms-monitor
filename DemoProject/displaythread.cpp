#include "displaythread.h"
#include "cancache.h"

DisplayThread::DisplayThread(QObject *parent) :
    QThread(parent)
{
    running = true;
}

void DisplayThread::run()
{
    while(running)
    {
        display();
        this->sleep(2);
        int size = CanCache::newInstance()->currentSize();
        log(QString::number(size).append(QString(" can frame ready for parse")));
    }

}

void DisplayThread::stop()
{
    running = false;
}
