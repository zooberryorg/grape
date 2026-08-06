#ifndef GRSHARED_H
#define GRSHARED_H

#include <QVector>

namespace GrShared {

inline const QVector<QString> baseTypes = {
    "animals",
    "fences",
    "items",
    "objects",
    "paths",
    "scenery",
};

inline const  QVector<QString> cTypes = {
    "uca",
    "ucb",
    "ucs",
    "ai"
};

}

#endif // GRSHARED_H
