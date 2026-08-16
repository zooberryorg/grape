#ifndef CBUILDING_H
#define CBUILDING_H

#include "cscenery.h"

class CBuilding : public CScenery
{
public:
    CBuilding(QString);
    void initMembers();
    void initCharInts();
};

#endif // CBUILDING_H
