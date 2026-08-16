#include "cpath.h"


CPath::CPath(QString path)
    : CScenery(path)
{
    m_type = AssetType::Path;
    initMembers();
    initCharInts();
}
