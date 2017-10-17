#include "cancache.h"
#include <QMutex>

CanCache* CanCache::instance_ = NULL;
QMutex lock;

CanCache* CanCache::newInstance(){
    if (NULL == instance_){
        static CanCache instanceT;
        instance_ = &instanceT;
//        parser = new CanParser();
    }
    return instance_;
};

void CanCache::addFrame(can_frame* frame){
    // use mask to remove the cluster information.
//    int id = frame.can_id& CAN_ID_MASK;
//    switch (id){
//        case BAMS_INF1:
//        case BAMS_INF2:
//        case BAMS_INF3:
//        case BAMS_INF4:
//        case BMS_INF:
//        case BMS_INF1:
//        case FAU_ALA:
//        case BMS_INF2:
//        case NOM_PAR:
//            frames.insert(frame.can_id, frame);
//            break;
//        default:
//            long long bytes;
//            memcpy(&bytes, frame.data, 8);
//            bytes = bytes & 0x000000FF;
//            frames.insert(frame.can_id + bytes, frame);
//        }
    if (this->currentSize() < MAX){
        frames.append(frame);
    }else{
        delete frame;
        frame=NULL;
    }
}
int CanCache::currentSize(){
    return frames.size();
}

can_frame* CanCache::get(){
    lock.lock();
    while (frames.isEmpty()){

    }
    can_frame* frame = frames.takeFirst();
    lock.unlock();
    return frame;
}

//int CanCache::parse(){
//    int size = this->currentSize();
//    int i = 0;
//    can_frame frame;
//    while (i < size){
//        frame = frames.first();
//        parser->parse(frame);
//        frames.removeFirst();
//        i++;
//    }
//    return size;
//}
