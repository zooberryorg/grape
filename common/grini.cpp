#include "grini.h"

QHash<QString, QString> GrINI::getKeyValuesInSection(const CSimpleIniA& ini, QString section)
{
    CSimpleIniA::TNamesDepend memberKeys;
    ini.GetAllKeys("Member", memberKeys);
    QHash<QString, QString> pairs;

    for ( const auto& key : memberKeys ) {
        QString value = QString(ini.GetValue(section.toStdString().c_str(), key.pItem));
        pairs.insert(QString(key.pItem), value);
    }

    return pairs;
}
