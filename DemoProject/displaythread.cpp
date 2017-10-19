#include "displaythread.h"
#include "cancache.h"

DataPool* datapool = DataPool::newInstance();
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
    }

}

void DisplayThread::stop()
{
    running = false;
}
