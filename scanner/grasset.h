#ifndef GRASSET_H
#define GRASSET_H

#include <QVector>
#include <QHash>
#include "grtexture.h"
#include "gricon.h"
#include "grshared.h"

class GrAsset
{
public:
    GrAsset();
    virtual ~GrAsset() = default;
    virtual void load() = 0;
    virtual void save() = 0;
    virtual GrShared::AssetTypes type() const = 0;
    void loadLayers();

protected:
    // graphics
    QVector<GrTexture> m_mFrames; // main sprite frames
    QVector<GrTexture> m_sFrames; // shadow frames
    GrTexture m_bgFrame; // bg frame

    // animation
    qint16 m_framems;

    // files
    QHash<QString, QHash<QString, QString>> m_config; // uca, ucb, ucs, ai files
    QHash<QString, QStringList> m_unlock;
    // for every key in allKeys, return its value (<key, value>, <key, value>, ..., n>)
    QHash<QString, GrIcon> m_icons;

    // ids
    QString m_codename;
    GrShared::AssetTypes m_type;

};

#endif // GRASSET_H
