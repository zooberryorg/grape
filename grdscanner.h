#ifndef GRDSCANNER_H
#define GRDSCANNER_H

#include <QString>
#include <QDir>
#include <QtLogging>
#include <QDirIterator>
#include <QHash>

#include "grshared.h"

class GrDScanner
{
public:
    GrDScanner(QDir dir);
    void validate();
    void load();

private:
    QDir dir;
    QHash<QString, QString> cPaths;
};

#endif // GRDSCANNER_H
