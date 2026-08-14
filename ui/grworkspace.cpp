#include <QSplitter>
#include <QHBoxLayout>

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

    // Canvas area
    canvasArea = new QFrame;
    canvasArea->setFrameShape(QFrame::Box);

    hSplitter->addWidget(projectTree);
    hSplitter->addWidget(canvasArea);
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
