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
    dataPool->store("zdy",2102);
    dataPool->store("zdl",50.6);
    dataPool->store("soc",89.5);
    bool debug = true;
    while(running)
    {

        if (debug == true){
            sendDebugPackage(parser, 0x18003001, 0x08, 0x130052C880F21F23);
            sendDebugPackage(parser, 0x18013001, 0x08, 0x0100640005A505A5);
            sendDebugPackage(parser, 0x18023001, 0x08, 0x1B1B1B1B1B1B1B1B);
            sendDebugPackage(parser, 0x18033001, 0x08, 0x1B1B1B1B1B1B1B1B);
            sendDebugPackage(parser, 0x18043001, 0x08, 0x0200520100640801);

            sendDebugPackage(parser, 0x18043002, 0x08, 0x0200520100750601);
        }else{
            // collection from Can Bus start.
            ycapi->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
            parser->parse(frame);
            // collection from Can Bus finish.
        }
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
