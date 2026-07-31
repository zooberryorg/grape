#ifndef GRPROJECT_H
#define GRPROJECT_H

#include <QVector>
#include <QHash>
#include "grtexture.h"

class grproject
{
public:
    grproject();
    void loadLayers();

private:
    // graphics
    QVector<GrTexture> m_mFrames; // main sprite frames
    QVector<GrTexture> m_sFrames; // shadow frames
    GrTexture m_bgFrame; // bg frame

    // animation
    qint16 m_framems;

    // files
    QHash<QString, QStringList> m_properties; // uca, ucb, ucs, ai files
    // for every key in allKeys, return its value (<key, value>, <key, value>, ..., n>)

    // ids
    qint16 m_nameId;
    QString codename;

};

#endif // GRPROJECT_H
