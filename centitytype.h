#ifndef CENTITYTYPE_H
#define CENTITYTYPE_H

#include <QHash>

class CEntityType
{
public:
    CEntityType();

protected:
    QHash<QString, QHash<QString, QString>> mConfig;
};

#endif // CENTITYTYPE_H
