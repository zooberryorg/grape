#ifndef GRPE_H
#define GRPE_H

#include <QString>

namespace GrPE
{
    struct Entry {
        unsigned int id;
        QString value;
    };

    QVector<Entry> getStringTables();
}

#endif // GRPE_H
