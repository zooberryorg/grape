#ifndef CBFUNIT_H
#define CBFUNIT_H

#include "centity.h"

class CBFUnit : public CEntity
{
public:
    CBFUnit(QString);
    virtual void load() = 0;
    virtual void save() = 0;
    virtual GrShared::AssetTypes type() const = 0;
};

#endif // CBFUNIT_H
