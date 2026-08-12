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
