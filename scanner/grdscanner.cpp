#include "grdscanner.h"
#include "canimal.h"
#include "cscenery.h"
#include "cbuilding.h"
#include "cfence.h"
#include "cpath.h"
#include "ctankfilter.h"
#include "grini.h"

GrDScanner::GrDScanner(QString rootDir)
    : rootDir(rootDir)
{
    // clean input dir
    this->rootDir = QDir::cleanPath(rootDir);

    loadTopLevels();
    findConfigFiles();
    loadAssets();
}

// Finds all valid folders for main game asset types
void GrDScanner::loadTopLevels() {
    for ( const auto& curPath : QDirListing(rootDir) ) {
        QString folderName = curPath.fileName().toLower();
        int level = depth(rootDir, curPath.filePath());

        if ( level == 0 && curPath.isDir() ) {
            int isGameDirFolder = GrShared::dFolders.contains( folderName );

            if ( isGameDirFolder )
                foundGameFolders.append( folderName );
        }
    }

    if ( foundGameFolders.empty() ) {
        // later send signal for popup error
        QString e = "Error: incorrect directory structure or no config files found at " + rootDir;
    }
}

// Finds all base config files for main game asset types given a root folder
void GrDScanner::findConfigFiles() { 
    for ( auto& folder : foundGameFolders ) {
        QString baseFolderPath = rootDir + '/' + folder;
        if ( folder == "animals" ) { // animals
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath,
                    {"ai", "uca"}
                )
            );
        } else if ( folder == "scenery" ) { // buildings, scenery, foliage
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath + '/' + "building",
                    {"ai", "ucs", "ucb"}
                )
            );
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath + '/' + "foliage",
                    {"ai", "ucs", "ucb"}
                )
            );
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath + '/' + "other",
                    {"ai", "ucs", "ucb"}
                )
            );
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath + '/' + "rock",
                    {"ai", "ucs", "ucb"}
                )
            );
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath + '/' + "terrain",
                    {"ai", "ucs", "ucb"}
                )
            );
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath + '/' + "toy",
                    {"ai", "ucs", "ucb"}
                )
            );
        } else if ( folder == "paths" || folder == "fences" ) { // paths, fences
            cPaths.append(
                findConfigPathsInDir(
                    baseFolderPath,
                    {"ai"}
                )
            );
        }
    }

    if ( cPaths.empty() ) {
        // later send signal for popup error
        QString e = "Error: no configuration files found at " + rootDir;
    }
}

// Helper function that scans a directory at root level for files with given exts
QStringList GrDScanner::findConfigPathsInDir(QString path, QStringList validExts) {
    QVector<QString> paths;
    bool exists = QDir(path).exists();
    QStringList pathFileList = QDir(path).entryList(QDir::Files);
    qDebug() << "Scanning:" << path << "exists:" << exists;
    qDebug() << "entryList:" << pathFileList;
    for ( const auto& curPath : QDirListing(path, QDirListing::IteratorFlag::FilesOnly) ) {
        QString ext = curPath.fileInfo().suffix().toLower();
        if ( validExts.contains( ext, Qt::CaseInsensitive ) ) {
            paths.append( curPath.filePath() );
        }
    }
    return paths;
}

// determined asset type
GrShared::AssetTypes GrDScanner::determineTypeFromFile(QString path) {
    CSimpleIniA ini;
    ini.SetUnicode();

    int rc = ini.LoadFile(path.toStdString().c_str());
    if ( rc < 0 ) {
        // error handling later
        // Error loading ini file at path:
    }

    QStringList members = GrINI::getFlagsInSection(path, "Member");

    if ( members.contains("animals") ) { // animals

        return AssetType::Animal;

    } else if ( members.contains("paths") ) { // paths

        return AssetType::Path;

    } else if ( members.contains("structures") || members.contains("shelters") ) {

        return AssetType::Building;

    } else if ( members.contains("scenery") || members.contains("light") || members.contains("rocks")
               || members.contains("foliage") || members.contains("habitatfoliage") || members.contains("zoofoliage") ) {

        return AssetType::Scenery;

    } else if ( GrINI::doesSectionExist(ini, "FilterSounds" ) ||
                GrINI::doesKeyInSectionExist(ini, "Characteristics/Integers", "cFilterUpkeep" )) {

        return AssetType::TankFilter;

    } else if ( members.contains("fence") || members.contains("lowfence") || members.contains("zoofences")
               || members.contains("highfence") || members.contains("habitatfences") ) {

       return AssetType::Fence;

   }

    return AssetType::None;
}

// Returns current directory depth relative to root path
int GrDScanner::depth(QString rootPath, QString curPath) {
    int _depth = 0;


    QStringView r(curPath); // root
    QStringView c(curPath); // current

    QChar separator = '/';
    _depth = c.count(separator) - r.count(separator);

    return _depth;
}

// returns all config paths
QStringList GrDScanner::getConfigPaths() {
    return cPaths;
}

// gathers all asset data from a directory and saves to memory
void GrDScanner::loadAssets() {

    for ( const auto& path : cPaths ) {
        AssetType type = determineTypeFromFile( path );

        switch (type) {
            case AssetType::Animal: {
                std::unique_ptr<CAnimal> animal = std::make_unique<CAnimal>( path );
                animal->graphicsLoader( rootDir );
                m_assets.push_back( std::move(animal) );
                break;
            }
            case AssetType::Scenery: {
                std::unique_ptr<CScenery> scenery = std::make_unique<CScenery>( path );
                scenery->graphicsLoader( rootDir );
                m_assets.push_back( std::move(scenery) );
                break;
            }
            case AssetType::Building: {
                std::unique_ptr<CBuilding> building = std::make_unique<CBuilding>( path );
                building->graphicsLoader( rootDir );
                m_assets.push_back( std::move(building) );
                break;
            }
            case AssetType::Fence: {
                std::unique_ptr<CFence> fence = std::make_unique<CFence>( path );
                fence->graphicsLoader( rootDir );
                m_assets.push_back( std::move(fence) );
                break;
            }
            case AssetType::Path: {
                std::unique_ptr<CPath> pathAsset = std::make_unique<CPath>( path );
                pathAsset->graphicsLoader( rootDir );
                m_assets.push_back( std::move(pathAsset) );
                break;
            }
            case AssetType::TankFilter: {
                std::unique_ptr<CTankFilter> tankFilter = std::make_unique<CTankFilter>( path );
                tankFilter->graphicsLoader( rootDir );
                m_assets.push_back( std::move(tankFilter) );
                break;
            }
            default:
                break;
        }
    }
}

std::vector<std::unique_ptr<GrAsset> > GrDScanner::assets()
{
    return std::move(m_assets);
}

void GrDScanner::deleteAsset(qint32 index) {
    m_assets.erase(m_assets.begin() + index);
}
