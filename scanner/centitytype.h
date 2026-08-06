#ifndef CENTITYTYPE_H
#define CENTITYTYPE_H

#include <QHash>
#include "grproject.h"

class CEntityType : public GrProject
{
public:
    CEntityType();
    virtual ~CEntityType() {};

protected:
    QHash<QString, QHash<QString, QString>> mConfig;
};

#endif // CENTITYTYPE_H
