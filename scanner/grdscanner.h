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
    QVector<DirEntry> configPaths();

private:
    // methods
    void loadTopLevels();
    void findConfigFiles();
    int depth(DirEntry rootPath, DirEntry curPath);
    void validate();
    QVector<DirEntry> findConfigPathsInDir(QString, QStringList);
    QVector<DirEntry> getConfigPaths();

    // fields
    DirEntry rootDir;
    QVector<DirEntry> cPaths;
    QString workspaceName;
    QStringList foundGameFolders;
};

#endif // GRDSCANNER_H
