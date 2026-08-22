#ifndef GRPE_H
#define GRPE_H

#include <QString>

namespace GrPE
{
    struct Entry {
        unsigned int id;
        QString value;
        QString dllFileName;
    };

    QVector<GrPE::Entry> getStringTables(const QString& path);
}

#endif // GRPE_H
