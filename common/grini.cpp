#include "grini.h"

QStringList GrINI::getKeyValuesInSection(QString section)
{
    CSimpleIniA::TNamesDepend memberKeys;
    ini.GetAllKeys("Member", memberKeys);
    QStringList members;

    for ( const auto& member : memberKeys ) {
        members.append(QString(member.pItem));
    }
}
