#include <QSplitter>
#include <QHBoxLayout>
#include <QToolbar>
#include <QActionGroup>
#include <QStackedWidget>

#include "grworkspace.h"
#include "grprojecttree.h"
#include "grasset.h"
#include "grdscanner.h"
#include "grproject.h"

GrWorkspace::GrWorkspace(QWidget *parent)
    : QWidget{parent}
{
    workspaceHLayout = new QHBoxLayout( this );
    hSplitter = new QSplitter( this );
    workspaceHLayout->addWidget( hSplitter );

    // file tree setup
    projectTree = new GrProjectTree;
    projectStack = new QStackedWidget;

    hSplitter->addWidget( projectTree );
    hSplitter->addWidget( projectStack );
    // hSplitter->setSizes({250, 524, 250});

    hSplitter->setStretchFactor(0, 0);
    hSplitter->setStretchFactor(1, 1);

    connect(projectTree, &GrProjectTree::assetSelected, this, &GrWorkspace::handleAssetSelected);
}

void GrWorkspace::addProject(QString dir)
{
    GrDScanner scanner( dir );
    GrProject* lastPage = nullptr;

   for ( auto& asset : scanner.assets() ) {
        GrAsset* assetPointer = asset.get();
        GrProject* page = new GrProject(this);
        projectStack->addWidget( page );

        m_projects.insert( asset->getProjectId(), page );
        asset->load();
        page->showAsset(assetPointer);
        projects.push_back( std::move( asset ) );
        projectTree->insertProject( assetPointer );

        lastPage = page;
    }

    if ( projects.empty() ) {
        // handle error when no files found
    }

    if ( lastPage ) {
        projectStack->setCurrentWidget( lastPage );
    }
}

void GrWorkspace::handleAssetSelected(GrAsset* asset)
{
    GrProject* page = m_projects.value( asset->getProjectId() );
    if ( !page ) {
        return;
    }

    projectStack->setCurrentWidget( page );
    page->showAsset( asset );
}
