#ifndef CANIMAL_H
#define CANIMAL_H

#include "cztunit.h"
#include "grini.h"

class CAnimal : public CZTUnit
{
public:
    CAnimal(QString);
    void load() override;
    void save() override;

    void initGlobals();
    void initAnimPaths();
    void initIcon();
    void initMembers();
    void initCharStrings();
    void initCharInts();
    void initCompatibleAnimals();
    void initSuitableObjects();
    void initDefaultLcid();
    void init1033();

    GrShared::SubtypeList subtypes() const override;
};

#endif // CANIMAL_H
