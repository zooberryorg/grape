#ifndef CENTITY_H
#define CENTITY_H

#include <QHash>
#include "grasset.h"

class CEntity : public GrAsset
{
public:
    CEntity();
    virtual ~CEntity() {};

protected:
    QHash<QString, QHash<QString, QString>> mConfig;
};

#endif // CENTITY_H
