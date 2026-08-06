#ifndef GRPROJECT_H
#define GRPROJECT_H

#include <QVector>
#include <QHash>
#include "grtexture.h"
#include "gricon.h"
#include "grshared.h"

class GrProject
{
public:
    GrProject();
    virtual void load() = 0;
    virtual void generateDirectory() = 0;
    GrShared::Types isType;
    void loadLayers();

protected:
    // graphics
    QVector<GrTexture> m_mFrames; // main sprite frames
    QVector<GrTexture> m_sFrames; // shadow frames
    GrTexture m_bgFrame; // bg frame

    // animation
    qint16 m_framems;

    // files
    QHash<QString, QStringList> m_properties; // uca, ucb, ucs, ai files
    QHash<QString, QStringList> m_unlock;
    // for every key in allKeys, return its value (<key, value>, <key, value>, ..., n>)
    QHash<QString, GrIcon> m_icons;

    // ids
    qint16 m_nameId;
    qint16 m_helpId;
    QString m_codename;

};

#endif // GRPROJECT_H
