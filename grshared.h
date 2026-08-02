#ifndef GRSHARED_H
#define GRSHARED_H

#include <QVector>

namespace GrShared {

inline const QVector<QString> types = {
    "ambient",
    "animals",
    "fences",
    "food",
    "freeform",
    "fringe",
    "guests",
    "items",
    "objects",
    "paths",
    "research",
    "scenario",
    "scenery",
    "sounds",
    "staff"
};

inline const  QVector<QString> cTypes = {
    "uca",
    "ucb",
    "ucs",
    "ai"
};

}

#endif // GRSHARED_H
