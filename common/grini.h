#ifndef GRINI_H
#define GRINI_H

// layer over simple ini that returns Qt friendly objects

#include <QStringList>
#include <QHash>
#include "SimpleIni.h"

class GrINI
{
public:
    static QHash<QString, QString> getKeyValuesInSection(const CSimpleIniA& ini, QString section);
    static void assignNewValuesToKeys(QHash<QString, QHash<QString, QString>>&, const QHash<QString, QString>&);
};

#endif // GRINI_H
