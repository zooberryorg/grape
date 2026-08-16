#ifndef GRASSET_H
#define GRASSET_H

#include <QVector>
#include <QHash>

#include "grtexture.h"
#include "grgfx.h"
#include "grshared.h"
#include "SimpleIni.h"

using AssetType = GrShared::AssetTypes;

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
    QVector<GrTexture> m_mFrames; // main sprite frames
    QVector<GrTexture> m_sFrames; // shadow frames
    GrTexture m_bgFrame; // bg frame

    // animation
    qint16 m_framems;

    // files
    QString m_cpath; // path to main config file
    QHash<QString, QHash<QString, QString>> m_intchars; // uca, ucb, ucs, ai files
    QHash<QString, QHash<QString, QString>> m_globals; // uca, ucb, ucs, ai files
    QHash<QString, QHash<QString, QString>> m_animpaths; // uca, ucb, ucs, ai files
    QHash<QString, QHash<QString, QString>> m_icon; // uca, ucb, ucs, ai files
    QStringList m_members; // uca, ucb, ucs, ai files
    QHash<QString, QHash<QString, QString>> m_strchars; // uca, ucb, ucs, ai files
    QHash<QString, QHash<QString, QString>> m_suitableobjects; // uca, ucb, ucs, ai files
    QHash<QString, QHash<QString, QString>> m_behaviorsets;
    QHash<QString, QHash<QString, QString>> m_ambientanims;
    QHash<QString, QHash<QString, QString>> m_defaultlcid;
    QHash<QString, QHash<QString, QString>> m_1033;
    QHash<QString, QHash<QString, QString>> m_animations;
    QHash<QString, QHash<QString, QString>> m_filtersounds;

    QHash<QString, QStringList> m_unlock;
    // for every key in allKeys, return its value (<key, value>, <key, value>, ..., n>)

    // ids
    QString m_projectname;
    QString m_projectid;
    GrShared::AssetTypes m_type;


};

#endif // GRASSET_H
