#include "grdscanner.h"

GrDScanner::GrDScanner(DirEntry rootDir, QString workspaceName)
    : rootDir(rootDir)
    , workspaceName(workspaceName)
{
    validate();
    loadTopLevels();
    findConfigFiles();
}

void GrDScanner::validate() {
    if (!rootDir.exists()) {
        // later send signal for popup error
        QString e = "Error: directory not found: " + rootDir.filePath();
    }
}

// Finds all valid folders for main game asset types
void GrDScanner::loadTopLevels() {
    for ( const auto& curPath : QDirListing(rootDir.filePath(), QDirListing::IteratorFlag::DirsOnly) ) {
        QString folderName = curPath.fileName().toLower();
        int level = depth(rootDir, curPath);

        if ( level == 0 && curPath.isDir() ) {
            int isGameDirFolder = GrShared::dFolders.contains( folderName );

            if ( isGameDirFolder )
                foundGameFolders.append( folderName );
        }
    }
}

// Finds all base config files for main game asset types given a root folder
void GrDScanner::findConfigFiles() {
    for ( auto& folder : foundGameFolders ) {
        if ( folder == "animals" ) {
            cPaths.append(
                findConfigPathsInDir(
                    rootDir.filePath() + folder,
                    {".ai", ".uca"}
                )
            );
        } else if ( folder == "scenery" ) {
            cPaths.append(
                findConfigPathsInDir(
                    rootDir.filePath() + folder + "/other",
                    {".ai", ".ucs", ".ucb"}
                )
            );
        } else if ( folder == "paths" ) {
            cPaths.append(
                findConfigPathsInDir(
                    rootDir.filePath() + folder,
                    {".ai"}
                )
            );
        }
    }
}

// Helper function that scans a directory at root level for files with given exts
QVector<DirEntry> GrDScanner::findConfigPathsInDir(QString path, QStringList validExts) {
    QVector<DirEntry> paths;
    for ( const auto& curPath : QDirListing(path, QDirListing::IteratorFlag::FilesOnly) ) {
        QString ext = curPath.fileInfo().suffix().toLower();
        if ( validExts.contains( ext, Qt::CaseInsensitive ) ) {
            paths.append( curPath );
        }
    }
    return paths;
}

// Returns current directory depth relative to root path
int GrDScanner::depth(DirEntry rootPath, DirEntry curPath) {
    int _depth = 0;


    QStringView r(curPath.filePath()); // root
    QStringView c(curPath.filePath()); // current

    QChar separator = QDir::separator();
    _depth = c.count(separator) - r.count(separator);

    return _depth;
}
