#include "grzip.h"


GrZIP::GrZIP(const QString& archivePath)
{
    memset(&m_archive, 0, sizeof(m_archive));
    m_isOpen = mz_zip_reader_init_file(&m_archive, archivePath.toUtf8().constData(), 0);
    if (!m_isOpen)
        setErrorFromMiniz();
}

GrZIP::~GrZIP()
{

}

QStringList GrZIP::fileNames() const
{

}

bool GrZIP::extractFileToBuffer(const QString &name, QByteArray &out) const
{

}

bool GrZIP::extractAllTo(const QString &destDir) const
{

}

void GrZIP::setErrorFromMiniz()
{

}
