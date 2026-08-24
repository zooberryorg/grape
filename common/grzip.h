#ifndef GRZIP_H
#define GRZIP_H

#include <QString>
#include <miniz.h>

class GrZIP
{
public:
    explicit GrZIP(const QString& archivePath);
    ~GrZIP();

    bool isOpen() const { return m_isOpen; }
    QString lastError() const { return m_lastError; }

    QStringList fileNames() const;
    bool extractFileToBuffer(const QString& name, QByteArray& out) const;
    bool extractAllTo(const QString& destDir) const;

private:
    mz_zip_archive m_archive;
    bool m_isOpen = false;
    mutable QString m_lastError;
    mz_zip_archive* archive() const { return const_cast<mz_zip_archive*>(&m_archive); }

    void setErrorFromMiniz() const;
};

#endif // GRZIP_H
