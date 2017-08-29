#include "collectionthread.h"
#include "datapool.h"
#include <sstream>
#include <stdio.h>
#include "structs.h"
#include "canparser.h"

CollectionThread::CollectionThread(QObject *parent) :
        QThread(parent)
{
    running = true;
    ycapi = new Ycapi();
    ycapi->OpenCan(250000);
}

void CollectionThread::run()
{
    DataPool* dataPool = DataPool::newInstance();
    CanParser* parser = new CanParser();
    connect(parser,SIGNAL(log(QString)),this,SIGNAL(log(QString)));
    can_frame frame;
    char buf[100]={0};
    int i;
    bool debug = false;
    while(running)
    {
        // collection from Can Bus start.
        if (debug == true){
            //            frame.can_id = 0x181E17F3;
            //            frame.can_dlc = 0x08;
            //            b = 0x00000A0050000010;
            //            for(int j = 0; j < 8; j++){
            //                frame.data[j] = b >> (j * 8) & 0xFF;
            //            }
            //            parser->parse(frame);
            //
            //            frame.can_id = 0x181E17F3;
            //            frame.can_dlc = 0x08;
            //            b = 0x00000B0040000011;
            //            for(int j = 0; j < 8; j++){
            //                frame.data[j] = b >> (j * 8) & 0xFF;
            //            }
            //            parser->parse(frame);
            frame.can_id = 0x18F212F3;
            frame.can_dlc = 0x08;
            long long b = 0x130052C880F21F23;
            for(int j = 0; j < 8; j++){
                frame.data[j] = b >> (j * 8) & 0xFF;
            }
        }else{
            ycapi->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
        }

        memset(buf,0,100);
        sprintf(buf,"<0x%x>  <%d>",frame.can_id,frame.can_dlc);
        for(i=0;i<frame.can_dlc;i++)
        {
            sprintf(buf,"%s 0x%x",buf,frame.data[i]);
        }
        log(QString(buf));
        parser->parse(frame);



        // collection from Can Bus finish.
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
