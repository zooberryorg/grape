#ifndef CENTITY_H
#define CENTITY_H

#include <QHash>
#include "grasset.h"
#include "grshared.h"

class CEntity : public GrAsset
{
public:
    CEntity(QString);
    virtual GrShared::SubtypeList subtypes() const { return { { "", "" } }; };
};

#endif // CENTITY_H
