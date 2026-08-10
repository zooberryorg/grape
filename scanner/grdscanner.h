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
    Q_DISABLE_COPY(GrDScanner);
    QVector<DirEntry> loadConfigPaths();
    void loadAssets();
    void deleteAsset(qint32);

private:
    // methods
    void loadTopLevels();
    void findConfigFiles();
    int depth(DirEntry rootPath, DirEntry curPath);
    void validate();
    QVector<DirEntry> findConfigPathsInDir(QString, QStringList);
    QVector<DirEntry> getConfigPaths();
    GrShared::AssetTypes determineTypeFromFile(QString);
    void generateProjectTree();

    // fields
    DirEntry rootDir;
    QVector<DirEntry> cPaths;
    QStringList foundGameFolders;
    std::vector<std::unique_ptr<GrAsset>> m_assets;
};

#endif // GRDSCANNER_H
