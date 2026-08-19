#include "grasset.h"
#include <QDir>

GrAsset::GrAsset(QString dir)
    : m_cpath(dir)
{
}

void GrAsset::initProjectName() {
    QFileInfo file(m_cpath);
    m_projectname = file.baseName();
    m_projectid = file.baseName();
}

QList<GrShared::Section *> GrAsset::allSections()
{
    return {
        &m_intchars,
        &m_globals,
        &m_animpaths,
        &m_icon,
        &m_strchars,
        &m_suitableobjects,
        &m_behaviorsets,
        &m_ambientanims,
        &m_defaultlcid,
        &m_1033,
        &m_animations,
        &m_filtersounds
    };
}
