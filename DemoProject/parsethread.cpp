#include "parsethread.h"

ParseThread::ParseThread()
{
    cache = CanCache::newInstance();
    parser = new CanParser();
}
void ParseThread::run()
{
    while(running)
    {  
        can_frame* frame = cache->get();
        parser->parse(frame);
        delete frame;
        frame=NULL;
//        log(QString::number(res).append(QString(" frames has been parsed.")));
//        this->sleep(1);
    }
}

void ParseThread::stop()
{
    running = false;
}
