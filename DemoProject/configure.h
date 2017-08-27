#ifndef CONFIGURE_H
#define CONFIGURE_H

#include "datapool.h"

class Configure
{
public:
    static Configure* newInstance();
    int getClusterNum();
    void setClusterId(int clusterId);
    int getClusterId();
private:
    Configure(){};
    ~Configure();
    static Configure* instance_;
//    DataPool* dataPool;
};

#endif // CONFIGURE_H
