#include "grasset.h"
#include <QDir>

GrAsset::GrAsset(QString dir)
    : m_cpath(dir)
{
}

void GrAsset::initProjectName() {
    QFileInfo file(m_cpath);
    m_projectname = file.baseName();
    m_projectid = file.baseName();
}

QList<GrShared::Section *> GrAsset::allSections()
{
    return {
        &m_intchars,
        &m_globals,
        &m_animpaths,
        &m_icon,
        &m_strchars,
        &m_suitableobjects,
        &m_behaviorsets,
        &m_ambientanims,
        &m_defaultlcid,
        &m_1033,
        &m_animations,
        &m_filtersounds
    };
}

QStringList GrAsset::graphicsPathBuilder()
{
    QHash<QString, Value> animationPaths = getAnimationPaths();
    QStringList graphicPaths;
    if (animationPaths.isEmpty())
        return {};

    for (const QString& folderName : animationPaths.keys() ) {
        switch (m_type) {
            case (AssetType::Building):
            case (AssetType::Fence):
            case (AssetType::Foliage):
            case (AssetType::Food):
            case (AssetType::Path):
            case (AssetType::Scenery):
            case (AssetType::Rubble):
            case (AssetType::TankFilter):
            case (AssetType::TankWall):
                graphicPaths.append( "objects/" + m_projectid + "/" + folderName);
                break;
            case (AssetType::Animal):
                graphicPaths.append( "animals/" + m_projectid + "/" + folderName);
                break;
            default:
                graphicPaths.append( "");
                break;
        }
    }

    return graphicPaths;
}

void GrAsset::graphicsLoader( const QString& rootPath )
{
    for ( const QString& path : graphicsPathBuilder() ) {
        QDir animationName(path);
        const QString& graphicPath = rootPath + "/" + path;
        GrGraphic* graphic = new GrGraphic;
        graphic->load(graphicPath);
        m_frames.insert(animationName.dirName(), graphic);
    }
}
