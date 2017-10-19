#include "collectionthread.h"
#include "datapool.h"
#include <sstream>
#include <stdio.h>
#include "structs.h"

CollectionThread::CollectionThread(QObject *parent) :
        QThread(parent)
{
    running = true;
#if defined (RELEASE)
    ycapi = new Ycapi();
    ycapi->OpenCan(250000);
#endif
    parser = new CanParser();
    connect(parser,SIGNAL(log(QString)),this,SIGNAL(log(QString)));
    cache = CanCache::newInstance();
}

void CollectionThread::sendDebugPackage(unsigned int id, unsigned char length, long long data){
//    can_frame* frame = new can_frame();
    can_frame frame;
    frame.can_id = id;
    frame.can_dlc = length;
    for(int j = 0; j < 8; j++){
        frame.data[j] = data >> (j * 8) & 0xFF;
    }
//    cache->addFrame(frame);
    parser->parse(&frame);
}

void CollectionThread::run()
{
    bool debug = false;
    while(running)
    {
        if (debug){
            sendDebugPackage(BAMS_INF1, 0x08, 0x130052C880F21F23);
            sendDebugPackage(BAMS_INF2, 0x08, 0x130052C880F21F23);
            sendDebugPackage(BAMS_INF3, 0x08, 0x0A0B0C0D0E0F0607);
            sendDebugPackage(BAMS_INF4, 0x08, 0x0A0B0C0D0E0F0607);
            int clusterNumber = 5;
            for (int i = 1; i <= clusterNumber; i++){
                // cluster 1
                sendDebugPackage(BMS_INF+i, 0x08, 0x130052C880F21F23);
                sendDebugPackage(BMS_INF1+i, 0x08, 0x0100640005A505A5);
                sendDebugPackage(FAU_ALA+i, 0x08, 0x1B1B1B1B1B1B1B1B);
                sendDebugPackage(BMS_INF2+i, 0x08, 0x1B1B1B1B1B1B1B1B);
                sendDebugPackage(NOM_PAR+i, 0x08, 0x0200520100640801);
                // module 1
                sendDebugPackage(MNOM_PAR+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(MVT_PAR1+i, 0x08, 0x21FA10150164401);
                sendDebugPackage(MVT_PAR2+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_V1+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_V2+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_V3+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_V4+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_V5+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_V6+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_T1+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(CELL_T2+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(PCBA_6803_1+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(PCBA_6803_2+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(PCBA_6803_3+i, 0x08, 0x21FA101F0041001);
                sendDebugPackage(PCBA_6803_4+i, 0x08, 0x21FA101F0041001);

                // module 2
                sendDebugPackage(MNOM_PAR+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(MVT_PAR1+i, 0x08, 0x21FA10150164405);
                sendDebugPackage(MVT_PAR2+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_V1+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_V2+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_V3+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_V4+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_V5+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_V6+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_T1+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(CELL_T2+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(PCBA_6803_1+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(PCBA_6803_2+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(PCBA_6803_3+i, 0x08, 0x21FA101F0041005);
                sendDebugPackage(PCBA_6803_4+i, 0x08, 0x21FA101F0041005);
            }
            this->msleep(100);
        }else{
            // collection from Can Bus start.
//            can_frame* frame = new can_frame();
            can_frame frame;
#if defined (RELEASE)
            ycapi->ReadCan(&frame.can_id,&frame.can_dlc,frame.data);
#endif
//            cache->addFrame(&frame);
            parser->parse(&frame);
            // collection from Can Bus finish.
        }
    }
}

void CollectionThread::stop()
{
    running = false;
}
