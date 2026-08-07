#include "grdscanner.h"

GrDScanner::GrDScanner(QDir rootDir, QString workspaceName)
    : rootDir(rootDir)
    , workspaceName(workspaceName)
{
    validate();
    loadTopLevels();
}

void GrDScanner::validate() {
    if (!rootDir.exists()) {
        // later send signal for popup error
        QString e = "Error: directory not found: " + rootDir.path();
    }
}

void GrDScanner::loadTopLevels() {
    for ( const auto& curPath : QDirListing(rootDir.path(), QDirListing::IteratorFlag::DirsOnly) ) {
        QString fileName = curPath.fileName();
        int level = depth(rootDir.path(), curPath.filePath());

        if ( level == 0 && curPath.isDir() ) {
            int isGameDirFolder = GrShared::dFolders.contains(curPath.fileName());

            if ( isGameDirFolder )
                foundGameFolders.append(curPath.fileName());
        }
    }
}

void GrDScanner::findConfigFiles() {
    for ( const auto& folder : foundGameFolders ) {
        if ( folder == "animals" ) {

        }
    }
}

int GrDScanner::depth(QString rootPath, QString curPath) {
    int _depth = 0;


    QStringView r(curPath); // root
    QStringView c(curPath); // current

    QChar separator = QDir::separator();
    _depth = c.count(separator) - r.count(separator);

    return _depth;
}
