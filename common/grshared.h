#ifndef GRSHARED_H
#define GRSHARED_H

#include <QVector>

namespace GrShared {

struct SubtypeDef {
    QString prefix;
    QString label;
};

using SubtypeList = QVector<SubtypeDef>;

enum PropertyGroup {
    ID, // name, era, helpid, project name
    Prey, // cPrey list
    Commerce, // purchase cost, upkeep, items sold
    Sounds,
    Graphics, // bg, fg, shadow layers, icons, plaques
    Slots,
    Terrain, // terrain and habitat prefs
    BehaviorSets,
    Needs,
    Exhibit,
    Keepers,
    Guests,
    Traits,
    Social,
    UI,
    Misc
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

struct Value {
    QString v;
    PropertyGroup group;
    WidgetType widgetType;
};

using Key = QHash<QString, Value>;
using Section = QHash<QString, Key>;
using SubtypeSections = QHash<QString, Section>;
using Config = std::vector<SubtypeSections*>;

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
    Foliage,
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

inline const QString GroupToString(PropertyGroup group) {
    switch(group) {
        case ( ID ):
            return "ID";
        case ( Prey ):
            return "Prey";
        case ( Commerce ):
            return "Commerce";
        case ( Sounds ):
            return "Sounds";
        case ( Graphics ):
            return "Graphics";
        case ( Slots ):
            return "Slots";
        case ( Terrain ):
            return "Terrain";
        case ( BehaviorSets ):
            return "Behavior Sets";
        case ( Needs ):
            return "Needs";
        case ( Exhibit ):
            return "Exhibit";
        case ( Keepers ):
            return "Keepers";
        case ( Guests ):
            return "Guests";
        case ( Traits ):
            return "Traits";
        case ( Social ):
            return "Social";
        case ( UI ):
            return "UI";
        case ( Misc ):
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
