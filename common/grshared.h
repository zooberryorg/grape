#ifndef GRSHARED_H
#define GRSHARED_H

#include <QVector>

namespace GrShared {

enum AssetTypes {
    Scenery,
    Fence,
    Building,
    Food,
    Rubble,
    TankFilter,
    Path,
    TankWall,
    Animal,
    Staff,
    Guest,
    Helicopter,
    Guide,
    MaintenanceWorker,
    Keeper,
    Ambient,
    None
};

inline const QVector<QString> dFolders = { // default folders
    "animals",
    "fences",
    "items",
    "objects",
    "paths",
    "scenery",
};

inline const  QVector<QString> cTypes = { // config file types
    "uca",
    "ucb",
    "ucs",
    "ai",
    "cfg"
};

}

#endif // GRSHARED_H
