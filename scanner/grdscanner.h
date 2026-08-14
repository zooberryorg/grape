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

class GrDScanner
{
public:
    GrDScanner(QString rootDir);
    Q_DISABLE_COPY(GrDScanner);
    QVector<QString> loadConfigPaths();
    void loadAssets();
    std::vector<std::unique_ptr<GrAsset>> assets();
    void deleteAsset(qint32);

private:
    // methods
    void loadTopLevels();
    void findConfigFiles();
    int depth(QString rootPath, QString curPath);
    QVector<QString> findConfigPathsInDir(QString, QStringList);
    QVector<QString> getConfigPaths();
    GrShared::AssetTypes determineTypeFromFile(QString);

    // fields
    QString rootDir;
    QVector<QString> cPaths;
    QStringList foundGameFolders;
    std::vector<std::unique_ptr<GrAsset>> m_assets;
};

#endif // GRDSCANNER_H
