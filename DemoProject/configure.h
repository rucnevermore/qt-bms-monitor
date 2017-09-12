#ifndef CONFIGURE_H
#define CONFIGURE_H

#include "datapool.h"

class Configure
{
public:
    static Configure* newInstance();
    int getClusterNum();
    int getMaxEventNum();
    void setClusterIndex(int clusterId);
    int getClusterIndex();
    int getMaxEventInOnePage();
    void setMaxEventInOnePage(int num);
    int getEventCurrentPageNum();
    void setEventCurrentPageNum(int num);
    int getEventTotal();
private:
    Configure(){};
    ~Configure();
    static Configure* instance_;
//    DataPool* dataPool;
};

#endif // CONFIGURE_H
