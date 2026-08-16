#ifndef CSCENERY_H
#define CSCENERY_H

#include "centity.h"

class CScenery : public CEntity
{
public:
    CScenery(QString);
    void load() override;
    void save() override;

    void initGlobals();
    void initIcon();
    void initMembers();
    void initCharInts();
    void initDefaultLcid();
    void init1033();
    void initAnimations();
};

#endif // CSCENERY_H
