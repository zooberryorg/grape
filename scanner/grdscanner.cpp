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
    QDirListing it(dir.path(), QDirIterator::Subdirectories);
    QString rootPath = dir.path();

    // update with user I/O to name project
    auto root = new TreeNode(workspaceName, nullptr);

    for ( const auto& curDir : QDirListing(rootPath, QDirListing::IteratorFlag::Recursive) ) {

        QString fileName = curDir.fileName();
        int level = depth(rootPath, curDir.filePath());
        int isTypeFolder = GrShared::types.contains(curDir.fileName());

        if ( isTypeFolder && level == 0 ) {

            QDirIterator typeIt(dir.path() + fileName, QDirIterator::Subdirectories);
            root->appendChild(new TreeNode(fileName, root));

            while (typeIt.hasNext()) {
                if (GrShared::cTypes.contains(typeIt.fileName())){
                    cPaths.insert(fileName, typeIt.fileName());
                }
            }
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
