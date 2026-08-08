#ifndef GRASSET_H
#define GRASSET_H

#include <QVector>
#include <QHash>
#include "grtexture.h"
#include "gricon.h"
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
    virtual GrShared::AssetTypes type() const = 0;
    void loadLayers();
    GrShared::AssetTypes getType() { return m_type; };

protected:
    // constants
    QString charInts = "Characteristics/Integers";
    QString charFloats = "Characteristics/Floats";

    // graphics
    QVector<GrTexture> m_mFrames; // main sprite frames
    QVector<GrTexture> m_sFrames; // shadow frames
    GrTexture m_bgFrame; // bg frame

    // animation
    qint16 m_framems;

    // files
    QString m_cpath; // path to main config file
    QHash<QString, QHash<QString, QString>> m_config; // uca, ucb, ucs, ai files
    QHash<QString, QStringList> m_unlock;
    // for every key in allKeys, return its value (<key, value>, <key, value>, ..., n>)
    QHash<QString, GrIcon> m_icons;

    // ids
    QString m_codename;
    GrShared::AssetTypes m_type;

    GrShared::AssetTypes determineTypeFromFile();

};

#endif // GRASSET_H
