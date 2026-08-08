#ifndef GRDSCANNER_H
#define GRDSCANNER_H

#include <QString>
#include <QDir>
#include <QtLogging>
#include <QDirIterator>
#include <QHash>

#include "grshared.h"
#include "grtreenode.h"
#include "SimpleIni.h"

using TreeNode = GrTreeNode;
using DirEntry = QDirListing::DirEntry;
using AssetType = GrShared::AssetTypes;

class GrAsset;
class CAnimal;

class GrDScanner
{
public:
    GrDScanner(DirEntry rootDir);
    QVector<DirEntry> configPaths();
    std::unique_ptr<GrAsset> assets();

private:
    // methods
    void loadTopLevels();
    void findConfigFiles();
    int depth(DirEntry rootPath, DirEntry curPath);
    void validate();
    QVector<DirEntry> findConfigPathsInDir(QString, QStringList);
    QVector<DirEntry> getConfigPaths();
    GrShared::AssetTypes determineTypeFromFile(QString);

    // fields
    DirEntry rootDir;
    QVector<DirEntry> cPaths;
    QStringList foundGameFolders;
};

#endif // GRDSCANNER_H
