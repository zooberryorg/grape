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
    QDirIterator it(dir.path(), QDirIterator::Subdirectories);

    // update with user I/O to name project
    auto root = new TreeNode(workspaceName, nullptr);

    while (it.hasNext()) {

        QString fileName = it.fileName();

        if (GrShared::types.contains(it.fileName()) && it.depth() == 0) {

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

    QStringView r(curPath);
    QStringView c(curPath);

    QChar separator = QDir::separator();
    _depth = c.count(separator) - r.count(separator);

    return _depth;
}
