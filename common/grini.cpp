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

void GrINI::assignNewValuesToKeys(QHash<QString, QHash<QString, QString>>& target, const QHash<QString, QString>& input) {
    QString section = target.begin().key();
    for (const auto& key : input.keys()) {
        if ( target[section].contains(key) ) {
            target[section][key] = input.value(key);
        }
    }
}
