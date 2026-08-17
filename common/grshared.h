#ifndef GRSHARED_H
#define GRSHARED_H

#include <QVector>

namespace GrShared {

enum PropertyGroup {
    ID, // name, era, helpid, project name
    Prey, // cPrey list
    Commerce,
    Sounds,
    Graphics,
    Slots,
    Terrain, // terrain and habitat prefs
    BehaviorSets,
    NeedsSatisfaction,
};

enum WidgetType {
    TerrainBuilder,
    PreyBuilder,
    AssetPicker,
    LineText,
    MultilineText,
    Switch,
    IdPicker,
    Integer,
    Float
};

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

inline const QString TypeToString(AssetTypes type) {
    switch(type) {
        case ( Scenery ):
            return "Scenery";
        case ( Fence ):
            return "Fences";
        case ( Building ):
            return "Buildings";
        case ( Food ):
            return "Food";
        case ( Rubble ):
            return "Rubble";
        case ( TankFilter ):
            return "Tank Filters";
        case ( Path ):
            return "Paths";
        case ( TankWall ):
            return "Tank Walls";
        case ( Animal ):
            return "Animals";
        case ( Staff ):
            return "Staff";
        case ( Guest ):
            return "Guests";
        case ( Helicopter ):
            return "Helicopters";
        case ( Guide ):
            return "Guides";
        case ( MaintenanceWorker ):
            return "Maintenance Workers";
        case ( Keeper ):
            return "Zookeepers";
        case ( Ambient ):
            return "Ambients";
        case ( None ):
        default:
            return "Misc";
    }
}

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
