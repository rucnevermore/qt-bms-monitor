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
    }
}

void ParseThread::stop()
{
    running = false;
}
