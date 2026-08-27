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

QList<QHash<QString, GrShared::Section> *> GrAsset::allSections()
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

QHash<QString, Value> GrAsset::getAnimationPaths(const QString& subtypePrefix) const
{
    const QString sectionName = GrINI::buildSectionName(subtypePrefix, "Animations");
    return m_animations.value(subtypePrefix).value(sectionName);
}

QStringList GrAsset::graphicsPathBuilder()
{
    QStringList graphicPaths;

    switch (m_type) {
        case (AssetType::Building):
        case (AssetType::Fence):
        case (AssetType::Foliage):
        case (AssetType::Food):
        case (AssetType::Path):
        case (AssetType::Scenery):
        case (AssetType::Rubble):
        case (AssetType::TankFilter):
        case (AssetType::TankWall): {
            const QHash<QString, Value> animationPaths = getAnimationPaths("");
            for (const QString& animationName : animationPaths.keys()) {
                const QString folderName = animationPaths.value(animationName).v;
                graphicPaths.append( "objects/" + m_projectid + "/" + folderName );
            }
            break;
        }
        case (AssetType::Animal): {
            const QHash<QString, Value> maleAnims = getAnimationPaths("m");
            for (const QString& animationName : maleAnims.keys()) {
                const QString folderName = maleAnims.value(animationName).v;
                graphicPaths.append( "animals/" + m_projectid + "/m" + folderName );
            }
            const QHash<QString, Value> femaleAnims = getAnimationPaths("f");
            for (const QString& animationName : femaleAnims.keys()) {
                const QString folderName = femaleAnims.value(animationName).v;
                graphicPaths.append( "animals/" + m_projectid + "/f" + folderName );
            }
            const QHash<QString, Value> youngAnims = getAnimationPaths("y");
            for (const QString& animationName : youngAnims.keys()) {
                const QString folderName = youngAnims.value(animationName).v;
                graphicPaths.append( "animals/" + m_projectid + "/y" + folderName );
            }
            break;
        }
        default:
            graphicPaths.append( "" );
            break;
    }

    return graphicPaths;
}

void GrAsset::graphicsLoader( const QString& rootPath )
{
    QStringList graphicsPaths = graphicsPathBuilder();
    for ( const QString& path : graphicsPaths ) {
        QDir animationName(path);
        const QString& graphicPath = rootPath + "/" + path;
        GrGraphic* graphic = new GrGraphic;
        graphic->load(graphicPath);
        m_frames.insert(animationName.dirName(), std::move(graphic));
    }
}
