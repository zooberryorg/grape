#include "grdscanner.h"

GrDScanner::GrDScanner(DirEntry rootDir, QString workspaceName)
    : rootDir(rootDir)
    , workspaceName(workspaceName)
{
    validate();
    loadTopLevels();
}

void GrDScanner::validate() {
    if (!rootDir.exists()) {
        // later send signal for popup error
        QString e = "Error: directory not found: " + rootDir.filePath();
    }
}

void GrDScanner::loadTopLevels() {
    for ( const auto& curPath : QDirListing(rootDir.filePath(), QDirListing::IteratorFlag::DirsOnly) ) {
        QString fileName = curPath.fileName();
        int level = depth(rootDir, curPath);

        if ( level == 0 && curPath.isDir() ) {
            int isGameDirFolder = GrShared::dFolders.contains(curPath.fileName());

            if ( isGameDirFolder )
                foundGameFolders.append(curPath);
        }
    }
}

void GrDScanner::findConfigFiles() {
    for ( const auto& folder : foundGameFolders ) {
        if ( folder.fileName() == "animals" ) {

        }
    }
}

QVector<DirEntry> GrDScanner::findConfigPathsInDir(DirEntry path, QStringList validExts) {
    QVector<DirEntry> paths;
    for ( const auto& curPath : QDirListing(path.filePath(), QDirListing::IteratorFlag::FilesOnly) ) {
        QString ext = curPath.fileInfo().suffix().toLower();
        if ( validExts.contains( ext, Qt::CaseInsensitive ) ) {
            paths.append( curPath );
        }
    }
}

int GrDScanner::depth(DirEntry rootPath, DirEntry curPath) {
    int _depth = 0;


    QStringView r(curPath.filePath()); // root
    QStringView c(curPath.filePath()); // current

    QChar separator = QDir::separator();
    _depth = c.count(separator) - r.count(separator);

    return _depth;
}
