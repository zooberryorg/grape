#include "grdscanner.h"

GrDScanner::GrDScanner(QDir dir) : dir(dir) {
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
    while (it.hasNext()) {
        QString fileName = it.fileName();
        if (GrShared::types.contains(it.fileName())) {
            QDirIterator typeIt(dir.path() + fileName, QDirIterator::Subdirectories);
            while (typeIt.hasNext()) {
                if (GrShared::cTypes.contains(typeIt.fileName())){
                    cPaths.insert(fileName, typeIt.fileName());
                }
            }
        }
    }
}
