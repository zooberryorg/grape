#include "cfence.h"


CFence::CFence(QString path)
    : CScenery(path)
{
    m_type = AssetType::Fence;
    initMembers();
    initCharInts();
}

void CFence::initMembers()
{
    m_members.clear();
    m_members.append("fence");
}

void CFence::initCharInts()
{

}
