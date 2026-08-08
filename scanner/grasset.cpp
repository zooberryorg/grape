#include "grasset.h"

GrAsset::GrAsset(QString dir)
    : m_cpath(dir)
{}

GrShared::AssetTypes GrAsset::determineTypeFromFile() {
    CSimpleIniA ini;
    ini.SetUnicode();

    int rc = ini.LoadFile(m_cpath.toStdString().c_str());
    if ( rc < 0 ) {
        // error handling later
        // Error loading ini file at path:
    }

    CSimpleIniA::TNamesDepend memberKeys;
    ini.GetAllKeys("Member", memberKeys);
    QStringList members;

    for ( const auto& member : memberKeys ) {
        members.append(QString(member.pItem));
    }

    if ( members.contains("animals") ) { // animals
        // do stuff
    } else if ( members.contains("paths") ) { // paths
        // do stuff
    } else if ( members.contains("structures") // buildings
               || members.contains("shelters")
        ) {
        // do stuff
    } else if ( members.contains("fence") // fences
               || members.contains("lowfence")
               || members.contains("zoofences")
        ) {
        // do stuff
    } else if ( members.contains("scenery") // scenery
               || members.contains("light")
               || members.contains("rocks")
               || members.contains("foliage")
               || members.contains("habitatfoliage")
               || members.contains("zoofoliage")
        ) {
        // do stuff
    }
}
