#ifndef GRASSET_H
#define GRASSET_H

#include <QVector>
#include <QHash>
#include <QMetaType>

#include "grgraphic.h"
#include "grgfx.h"
#include "grshared.h"
#include "SimpleIni.h"

using AssetType = GrShared::AssetTypes;
using Widget = GrShared::WidgetType;
using Group = GrShared::PropertyGroup;
using Value = GrShared::Value;

class GrAsset
{
public:
    GrAsset();
    GrAsset(QString);
    virtual ~GrAsset() = default;
    virtual void load() = 0;
    virtual void save() = 0;
    QString name() { return m_projectname; };
    void loadLayers();
    void initProjectName();
    GrShared::AssetTypes getType() { return m_type; };
    QString getProjectId() { return m_projectid; };
    void setProjectId(const QString& id) { m_projectid = id; };
    QString getProjectName() { return m_projectname; };
    void setProjectName(const QString& name ) { m_projectname = name; };
    QList<GrShared::Section*> allSections();
    QHash<QString, Value> getAnimationPaths() { return m_animations[animations]; };
    QStringList graphicPathBuilder();

protected:
    // constants
    QString charInts = "Characteristics/Integers";
    QString charFloats = "Characteristics/Floats";
    QString charStrings = "Characteristics/Strings";
    QString cSuitableObjects = "cSuitableObjects";
    QString cCompatibleAnimals = "cCompatibleAnimals";
    QString cCompatibleTerrain = "cCompatibleTerrain";
    QString animPaths = "AnimPath";
    QString animations = "Animations";
    QString sounds = "Sounds";
    QString behaviorSet = "BehaviorSet";
    QString ambientAnims = "AmbientAnims";
    QString defaultLcid = "defaultLCID";
    QString _1033 = "1033";
    QString globals = "Global";
    QString icons = "Icon";
    QString filterSounds = "FilterSounds";

    // texture rgba data
    QVector<GrGraphic> m_mFrames; // main sprite frames
    QVector<GrGraphic> m_sFrames; // shadow frames
    GrGraphic m_bgFrame; // bg frame

    // animation
    qint16 m_framems;

    // files
    QString m_cpath; // path to main config file
    GrShared::Section m_intchars; // uca, ucb, ucs, ai files
    GrShared::Section m_globals; // uca, ucb, ucs, ai files
    GrShared::Section m_animpaths; // uca, ucb, ucs, ai files
    GrShared::Section m_icon; // uca, ucb, ucs, ai files
    QStringList m_members; // uca, ucb, ucs, ai files
    GrShared::Section m_strchars; // uca, ucb, ucs, ai files
    GrShared::Section m_suitableobjects; // uca, ucb, ucs, ai files
    GrShared::Section m_behaviorsets;
    GrShared::Section m_ambientanims;
    GrShared::Section m_defaultlcid;
    GrShared::Section m_1033;
    GrShared::Section m_animations;
    GrShared::Section m_filtersounds;

    QHash<QString, QStringList> m_unlock;
    // for every key in allKeys, return its value (<key, value>, <key, value>, ..., n>)

    // ids
    QString m_projectname;
    QString m_projectid;
    GrShared::AssetTypes m_type;
};

Q_DECLARE_METATYPE(GrAsset*)

#endif // GRASSET_H
