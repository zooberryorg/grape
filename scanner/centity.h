#ifndef CENTITY_H
#define CENTITY_H

#include <QHash>
#include "grasset.h"

class CEntity : public GrAsset
{
public:
    CEntity(QString);
    virtual void load() = 0;
    virtual void save() = 0;
    virtual GrShared::AssetTypes type() const = 0;
    virtual ~CEntity() {};
};

#endif // CENTITY_H
