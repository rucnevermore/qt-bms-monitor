#ifndef CANCACHE_H
#define CANCACHE_H

#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <QList>
#include "canparser.h"

#define MAX 3000
#define SET 100

class CanCache
{
public:
    static CanCache* newInstance();
    void addFrame(can_frame* frame);
//    int parse();
    int currentSize();
    can_frame* get();
private:
    CanCache(){};
    QList<can_frame*> frames;
    static CanCache* instance_;
//    CanParser* parser;
};

#endif // CANCACHE_H
