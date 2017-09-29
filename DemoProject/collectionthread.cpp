#include "collectionthread.h"
#include "datapool.h"
#include <sstream>
#include <stdio.h>
#include "structs.h"

CollectionThread::CollectionThread(QObject *parent) :
        QThread(parent)
{
    running = true;
//    ycapi = new Ycapi();
//    ycapi->OpenCan(250000);
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

            sendDebugPackage(parser, BAMS_INF1, 0x08, 0x130052C880F21F23);
            sendDebugPackage(parser, BAMS_INF2, 0x08, 0x130052C880F21F23);
            sendDebugPackage(parser, BAMS_INF3, 0x08, 0x0A0B0C0D0E0F0607);
            sendDebugPackage(parser, BAMS_INF4, 0x08, 0x0A0B0C0D0E0F0607);

            // cluster 1
            sendDebugPackage(parser, BMS_INF+1, 0x08, 0x130052C880F21F23);
            sendDebugPackage(parser, BMS_INF1+1, 0x08, 0x0100640005A505A5);
            sendDebugPackage(parser, FAU_ALA+1, 0x08, 0x1B1B1B1B1B1B1B1B);
            sendDebugPackage(parser, BMS_INF2+1, 0x08, 0x1B1B1B1B1B1B1B1B);
            sendDebugPackage(parser, NOM_PAR+1, 0x08, 0x0200520100640801);
            // module 1
            sendDebugPackage(parser, MNOM_PAR+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, MVT_PAR1+1, 0x08, 0x21FA10150164411);
            sendDebugPackage(parser, MVT_PAR2+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_V1+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_V2+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_V3+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_V4+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_V5+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_V6+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_T1+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, CELL_T2+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, PCBA_6803_1+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, PCBA_6803_2+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, PCBA_6803_3+1, 0x08, 0x21FA101F0041011);
            sendDebugPackage(parser, PCBA_6803_4+1, 0x08, 0x21FA101F0041011);

            // module 2
            sendDebugPackage(parser, MNOM_PAR+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, MVT_PAR1+1, 0x08, 0x21FA10150164405);
            sendDebugPackage(parser, MVT_PAR2+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_V1+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_V2+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_V3+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_V4+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_V5+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_V6+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_T1+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, CELL_T2+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, PCBA_6803_1+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, PCBA_6803_2+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, PCBA_6803_3+1, 0x08, 0x21FA101F0041005);
            sendDebugPackage(parser, PCBA_6803_4+1, 0x08, 0x21FA101F0041005);

            // cluster 2
            sendDebugPackage(parser, NOM_PAR+2, 0x08, 0x0200520100750601);
        }else{
            // collection from Can Bus start.
//            ycapi->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
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
