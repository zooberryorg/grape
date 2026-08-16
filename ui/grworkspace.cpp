#include <QSplitter>
#include <QHBoxLayout>
#include <QToolbar>
#include <QActionGroup>

#include "grworkspace.h"
#include "grprojecttree.h"
#include "grasset.h"
#include "grdscanner.h"

GrWorkspace::GrWorkspace(QWidget *parent)
    : QWidget{parent}
{
    workspaceHLayout = new QHBoxLayout(this);
    hSplitter = new QSplitter;
    workspaceHLayout->addWidget(hSplitter);

    // file tree setup
    projectTree = new GrProjectTree;

    // toolbar (right sidebar)
    QToolBar* toolbar = new QToolBar;
    toolbar->setOrientation(Qt::Vertical);
    toolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);

    QActionGroup* group = new QActionGroup(this);
    group->setExclusive(true);

    QAction* idTab = toolbar->addAction(QIcon(":/icons/id.svg"), "ID Settings");
    idTab->setCheckable(true);
    group->addAction(idTab);

    // Canvas area
    canvasArea = new QFrame;
    canvasArea->setFrameShape(QFrame::Box);

    hSplitter->addWidget(projectTree);
    hSplitter->addWidget(canvasArea);
    hSplitter->addWidget(toolbar);
    hSplitter->setSizes({250, 750});
}

void GrWorkspace::addProject(QString dir)
{
    GrDScanner scanner(dir);

   for ( auto& asset : scanner.assets() ) {
        GrAsset* assetPointer = asset.get();
        asset->load();
        projects.push_back(std::move(asset));
        projectTree->insertProject(assetPointer);
    }

    if ( projects.empty() ) {
        // handle error when no files found
    }
}
