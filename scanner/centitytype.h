#ifndef CENTITYTYPE_H
#define CENTITYTYPE_H

#include <QHash>

class CEntityType
{
public:
    CEntityType();
    virtual ~CEntityType() {};

protected:
    QHash<QString, QHash<QString, QString>> mConfig;
};

#endif // CENTITYTYPE_H
