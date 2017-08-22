#include "collectionthread.h"
#include "datapool.h"
#include <sstream>
//#include <linux/can.h>
//#include "ycapi.h"

CollectionThread::CollectionThread(QObject *parent) :
        QThread(parent)
{
    running = true;
}

struct can_frame {
        unsigned int     can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
        unsigned char    can_dlc; /* data length code: 0 .. 8 */
        unsigned char    data[8];
};

void CollectionThread::run()
{
    DataPool* dataPool = DataPool::newInstance();
    struct can_frame frame;
    double pjdy_1 = 12;
    double pjdy_2 = 24;
    int pBar_soc = 1;
    int collectionNum = 1;
    char buf[100]={0};
    int i;

    while(running)
    {
//        log(QString::fromStdString("collection data from Can bus in time " + getstring(collectionNum++) + "..."));

        // collection from Can Bus start.
       // ycapiT->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
        frame.can_id = 0x1F1F1F1F;
        frame.can_dlc = 0x08;
        QString datav = "0102030405060708";
        memcpy(frame.data, datav.toLocal8Bit().data(), datav.length()) ;
        memset(buf,0,100);
//        frame.data = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

        sprintf(buf,"<0x%x>  <%d>",frame.can_id,frame.can_dlc);
        for(i=0;i<frame.can_dlc;i++)
        {
//            printf("xxx:%x  ",frame.data[i]);
            sprintf(buf,"%s 0x%x",buf,frame.data[i]);
        }
        log(QString(buf));

        // collection from Can Bus finish.
        dataPool->store("pjdy_1", pjdy_1++);
        dataPool->store("pjdy_2", pjdy_2++);
        dataPool->store("pBar_soc", pBar_soc++);
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
