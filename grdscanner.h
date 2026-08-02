#ifndef GRDSCANNER_H
#define GRDSCANNER_H

#include <QString>
#include <QDir>
#include <QtLogging>

#include "grshared.h"

class GrDScanner
{
public:
    GrDScanner(QDir dir);
    void validate();
    void load();

private:
    QDir dir;
};

#endif // GRDSCANNER_H
