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
}

void GrWorkspace::addProject(QString dir)
{
    GrDScanner scanner( dir );

   for ( auto& asset : scanner.assets() ) {
        GrAsset* assetPointer = asset.get();
        asset->load();
        projects.push_back( std::move( asset ) );
        projectTree->insertProject( assetPointer );
    }

    if ( projects.empty() ) {
        // handle error when no files found
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
