#include "collectionthread.h"
#include "datapool.h"
#include <sstream>
#include <stdio.h>
#include "structs.h"

CollectionThread::CollectionThread(QObject *parent) :
        QThread(parent)
{
    running = true;
    ycapi = new Ycapi();
    ycapi->OpenCan(250000);
}

void CollectionThread::sendDebugPackage(CanParser* parser, unsigned int id, unsigned char length, long long data){
    can_frame frame;
    frame.can_id = id;
    frame.can_dlc = length;
    for(int j = 0; j < 8; j++){
        frame.data[j] = data >> (j * 8) & 0xFF;
    }
    parser->parse(frame);
}

void CollectionThread::run()
{
    DataPool* dataPool = DataPool::newInstance();
    CanParser* parser = new CanParser();
    connect(parser,SIGNAL(log(QString)),this,SIGNAL(log(QString)));
    can_frame frame;
    char buf[100]={0};
    int i;
    dataPool->store("cluster_number", 10);
    dataPool->store("zdy",2102);
    dataPool->store("zdl",50.6);
    dataPool->store("soc",89.5);
    bool debug = true;
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

            sendDebugPackage(parser, 0x18F212F3, 0x08, 0x130052C880F21F23);
            sendDebugPackage(parser, 0x181817F3, 0x08, 0x0200520100640801);
            sendDebugPackage(parser, 0x18F214F3, 0x08, 0x1B1B1B1B1B1B1B1B);
            sendDebugPackage(parser, 0x181817F4, 0x08, 0x0200520100750601);
        }else{
            ycapi->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
            parser->parse(frame);
        }

//        memset(buf,0,100);
//        sprintf(buf,"<0x%x>  <%d>",frame.can_id,frame.can_dlc);
//        for(i=0;i<frame.can_dlc;i++)
//        {
//            sprintf(buf,"%s 0x%x",buf,frame.data[i]);
//        }
//        log(QString(buf));


        // collection from Can Bus finish.

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
