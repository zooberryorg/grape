#ifndef CBUILDING_H
#define CBUILDING_H

#include "cscenery.h"

class CBuilding : public CScenery
{
public:
    CBuilding(QString);
    void initMembers();
    void initCharInts();
    GrShared::Config allSections() override;
};

#endif // CBUILDING_H
