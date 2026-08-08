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

        return AssetType::Animal;

    } else if ( members.contains("paths") ) { // paths

        return AssetType::Path;

    } else if ( members.contains("structures") || members.contains("shelters") ) {

        return AssetType::Building;

    } else if ( members.contains("fence") || members.contains("lowfence") || members.contains("zoofences") ) {

        return AssetType::Fence;

    } else if ( members.contains("scenery") || members.contains("light") || members.contains("rocks")
               || members.contains("foliage") || members.contains("habitatfoliage") || members.contains("zoofoliage") ) {

        return AssetType::Scenery;

    }

    return AssetType::None;
}
