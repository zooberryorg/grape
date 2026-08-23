#include "grzip.h"
#include <QStringList>

GrZIP::GrZIP(const QString& archivePath)
{
    memset(&m_archive, 0, sizeof(m_archive));
    m_isOpen = mz_zip_reader_init_file(&m_archive, archivePath.toUtf8().constData(), 0);
    if (!m_isOpen)
        setErrorFromMiniz();
}

GrZIP::~GrZIP()
{
    if (m_isOpen)
        mz_zip_reader_end(&m_archive);
}

QStringList GrZIP::fileNames() const
{
    QStringList names;
    if (!m_isOpen) return names;

    mz_zip_archive* archive = const_cast<mz_zip_archive*>(&m_archive);

    const mz_uint count = mz_zip_reader_get_num_files(archive);
    for (mz_uint i = 0; i < count; ++i) {
        mz_zip_archive_file_stat stat;
        if (mz_zip_reader_file_stat(archive, i, &stat))
            names << QString::fromUtf8(stat.m_filename);
    }
    return names;
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
