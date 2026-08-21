#include <QSplitter>
#include <QHBoxLayout>
#include <QToolbar>
#include <QActionGroup>
#include <QStackedWidget>
#include <QStatusBar>

#include "grworkspace.h"
#include "grprojecttree.h"
#include "grasset.h"
#include "grdscanner.h"
#include "grproject.h"
#include "grstatusbar.h"
#include "grlangtablebrowser.h"

GrWorkspace::GrWorkspace(QWidget *parent)
    : QWidget{parent}
{
    statusBar = new GrStatusBar( this );
    workspaceVLayout = new QVBoxLayout( this );

    vSplitter = new QSplitter(Qt::Vertical, this);
    hSplitter = new QSplitter(Qt::Horizontal, this);

    workspaceVLayout->setContentsMargins(5, 5, 5, 5);
    workspaceVLayout->addWidget(vSplitter);

    leftSidebarLayout = new QVBoxLayout;
    leftSidebarLayout->setContentsMargins(0, 0, 0, 0);

    // file tree setup
    projectTree = new GrProjectTree;
    projectStack = new QStackedWidget;

    // lang table
    GrLangTableBrowser* langBrowser = new GrLangTableBrowser(this, "C:\\Program Files (x86)\\Microsoft Games\\Zoo Tycoon CC\\lang200.dll");

    leftSidebarLayout->addWidget(projectTree);
    leftSidebarLayout->addWidget(langBrowser);
    QWidget* leftSidebar = new QWidget;

    leftSidebar->setLayout(leftSidebarLayout);

    hSplitter->addWidget( leftSidebar );
    hSplitter->addWidget( projectStack );
    // hSplitter->setSizes({250, 524, 250});
    vSplitter->addWidget(hSplitter);
    vSplitter->addWidget(statusBar);

    hSplitter->setStretchFactor(0, 0);
    hSplitter->setStretchFactor(1, 1);

    for (int i = 1; i < vSplitter->count(); ++i)
        vSplitter->handle(i)->setAttribute(Qt::WA_Hover, true);

    for (int i = 1; i < hSplitter->count(); ++i)
        hSplitter->handle(i)->setAttribute(Qt::WA_Hover, true);

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
