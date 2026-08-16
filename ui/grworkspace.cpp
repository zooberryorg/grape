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
    hSplitter = new QSplitter(this);
    workspaceHLayout->addWidget(hSplitter);

    // file tree setup
    projectTree = new GrProjectTree;

    // toolbar (right sidebar)
    QToolBar* toolbar = new QToolBar;
    toolbar->setOrientation(Qt::Vertical);
    toolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    toolbar->setMaximumWidth(50);

    QActionGroup* group = new QActionGroup(this);
    group->setExclusive(true);

    QAction* idTab = toolbar->addAction(QIcon(":/icons/id.svg"), "ID Settings");
    idTab->setCheckable(true);
    group->addAction(idTab);

    QAction* moneyTab = toolbar->addAction(QIcon(":/icons/coin.svg"), "Finance Settings");
    moneyTab->setCheckable(true);
    group->addAction(moneyTab);

    QWidget* toolbarFrame = new QWidget(this);
    QHBoxLayout* toolbarLayout = new QHBoxLayout(toolbarFrame);
    QVBoxLayout* configLayout = new QVBoxLayout();

    toolbarLayout->addWidget(toolbar);
    toolbarLayout->addLayout(configLayout);

    QWidget* placeholder = new QWidget(toolbarFrame);
    configLayout->addWidget(placeholder);
    placeholder->setMinimumWidth(200);

    // Canvas area
    canvasArea = new QFrame;
    canvasArea->setFrameShape(QFrame::Box);

    hSplitter->addWidget(projectTree);
    hSplitter->addWidget(canvasArea);
    hSplitter->addWidget(toolbarFrame);
    hSplitter->setSizes({250, 524, 250});

    hSplitter->setStretchFactor(0, 0);
    hSplitter->setStretchFactor(1, 1);
    hSplitter->setStretchFactor(2, 0);
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
