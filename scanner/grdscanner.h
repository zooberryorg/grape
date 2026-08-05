#ifndef GRDSCANNER_H
#define GRDSCANNER_H

#include <QString>
#include <QDir>
#include <QtLogging>
#include <QDirIterator>
#include <QHash>

#include "grshared.h"
#include "grtreenode.h"

using TreeNode = GrTreeNode;

class GrDScanner
{
public:
    GrDScanner(QDir dir, QString workspaceName);
    void validate();
    void load();

private:
    QDir dir;
    QHash<QString, QString> cPaths;
    QString workspaceName;
};

#endif // GRDSCANNER_H
