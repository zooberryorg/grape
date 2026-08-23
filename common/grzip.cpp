#include "grzip.h"
#include <QStringList>

#include <QFileInfo>
#include <QDir>

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

    const mz_uint count = mz_zip_reader_get_num_files(archive());
    for (mz_uint i = 0; i < count; ++i) {
        mz_zip_archive_file_stat stat;
        if (mz_zip_reader_file_stat(archive(), i, &stat))
            names << QString::fromUtf8(stat.m_filename);
    }
    return names;
}

bool GrZIP::extractFileToBuffer(const QString &name, QByteArray &out) const
{
    if (!m_isOpen) return false;

    size_t size = 0;
    void* data = mz_zip_reader_extract_file_to_heap(archive(), name.toUtf8().constData(), &size, 0);
    if (!data) {
        const_cast<GrZIP*>(this)->setErrorFromMiniz();
        return false;
    }

    out = QByteArray(static_cast<const char*>(data), static_cast<int>(size));
    mz_free(data);
    return true;
}

bool GrZIP::extractAllTo(const QString &destDir) const
{
    if (!m_isOpen) {
        m_lastError = "Archive is not open";
        return false;
    }

    QDir dir(destDir);
    if (!dir.exists() && !dir.mkpath(".")) {
        m_lastError = "Failed to create destination directory: " + destDir;
        return false;
    }

    const mz_uint count = mz_zip_reader_get_num_files(archive());

    for (mz_uint i = 0; i < count; ++i) {
        mz_zip_archive_file_stat stat;
        if (!mz_zip_reader_file_stat(archive(), i, &stat)) {
            setErrorFromMiniz();
            return false;
        }

        const QString entryName = QString::fromUtf8(stat.m_filename);
        const QString outPath = dir.filePath(entryName);

        if (mz_zip_reader_is_file_a_directory(archive(), i)) {
            if (!QDir().mkpath(outPath)) {
                m_lastError = "Failed to create directory: " + outPath;
                return false;
            }
            continue;
        }

        const QFileInfo zip(outPath);
        if (!QDir().mkpath(zip.absolutePath())) {
            m_lastError = "Failed to create directory: " + zip.absolutePath();
            return false;
        }

        if (!mz_zip_reader_extract_to_file(archive(), i, outPath.toUtf8().constData(), 0)) {
            setErrorFromMiniz();
            return false;
        }
    }

    return true;
}

void GrZIP::setErrorFromMiniz() const
{

}
