#include "cbuilding.h"


CBuilding::CBuilding(QString path)
    : CScenery(path)
{
    m_type = AssetType::Scenery;
    initMembers();
    initCharInts();
}


void CBuilding::initMembers () {
    m_members.clear();
    m_members.append("structures");
}

void CBuilding::initCharInts() {

}
