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
    GrDScanner(QDir rootDir, QString workspaceName);
    void validate();
    int depth(QString rootPath, QString curPath);
    QVector<QDir> getConfigPaths();

private:
    void loadTopLevels();
    void findConfigFiles();
    QVector<QDir> saveConfigPathsInDir(QDir);
    QDir rootDir;
    QHash<QString, QString> cPaths;
    QString workspaceName;
    QStringList foundGameFolders;
};

#endif // GRDSCANNER_H
