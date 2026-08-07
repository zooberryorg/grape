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
using DirEntry = QDirListing::DirEntry;

class GrDScanner
{
public:
    GrDScanner(DirEntry rootDir, QString workspaceName);
    void validate();
    QVector<DirEntry> getConfigPaths();

private:
    void loadTopLevels();
    void findConfigFiles();
    int depth(DirEntry rootPath, DirEntry curPath);
    QVector<DirEntry> saveConfigPathsInDir(DirEntry);
    DirEntry rootDir;
    QHash<QString, QString> cPaths;
    QString workspaceName;
    QStringList foundGameFolders;
};

#endif // GRDSCANNER_H
