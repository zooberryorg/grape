#include "grdscanner.h"

GrDScanner::GrDScanner(QDir dir, QString workspaceName)
    : dir(dir)
    , workspaceName(workspaceName)
{
    validate();
    load();
}

void GrDScanner::validate() {
    if (!dir.exists()) {
        // later send signal for popup error
        QString e = "Error: directory not found: " + dir.path();
    }
}

void GrDScanner::load() {
    QString rootPath = dir.path();

    // update with user I/O to name project
    auto root = new TreeNode(workspaceName, nullptr);

    for ( const auto& curPath : QDirListing(rootPath, QDirListing::IteratorFlag::Recursive) ) {
        QString fileName = curPath.fileName();
        int level = depth(rootPath, curPath.filePath());

        if ( level == 0 && curPath.isDir() ) {
            int isTypeFolder = GrShared::baseTypes.contains(curPath.fileName());

            if ( isTypeFolder )
                root->appendChild(new TreeNode(fileName, root));
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
