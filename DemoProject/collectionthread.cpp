#include "collectionthread.h"
#include "datapool.h"
#include <sstream>
#include <stdio.h>
#include "structs.h"
#include "canparser.h"
//#include <linux/can.h>
//#include "ycapi.h"

CollectionThread::CollectionThread(QObject *parent) :
        QThread(parent)
{
    running = true;
}

void CollectionThread::run()
{
    DataPool* dataPool = DataPool::newInstance();
    CanParser* parser = new CanParser();
    connect(parser,SIGNAL(log(QString)),this,SIGNAL(log(QString)));
    CanFrame frame;
    double pjdy_1 = 12;
    double pjdy_2 = 24;
    int pBar_soc = 1;
    char buf[100]={0};
    int i;

    while(running)
    {
        // collection from Can Bus start.
       // ycapiT->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
        frame.can_id = 0x18F212F3;
        frame.can_dlc = 0x08;
//        frame.data = {0x00, 0x00, 0x52, 0xC8, 0x0C, 0xE5, 0x1F, 0x23};
        long long b = 0x000052C80CE51F23;
        memcpy(frame.data, QString::number(b).toLocal8Bit().data(), frame.can_dlc) ;
        memset(buf,0,100);
        sprintf(buf,"<0x%x>  <%d>",frame.can_id,frame.can_dlc);
        for(i=0;i<frame.can_dlc;i++)
        {
            sprintf(buf,"%s 0x%x",buf,frame.data[i]);
        }
        log(QString(buf));
        parser->parse(frame);

        // collection from Can Bus finish.
        dataPool->store("pjdy_1", pjdy_1++);
        dataPool->store("pjdy_2", pjdy_2++);
        dataPool->store("pBar_soc", pBar_soc++);
        dataPool->store("cluster_number", 10);
        this->sleep(1);
    }

}

string CollectionThread::getstring(int n)
{
    std::stringstream newstr;
    newstr<<n;
    return newstr.str();
}

void CollectionThread::stop()
{
    running = false;
}
