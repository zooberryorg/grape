#include "grapew.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    central = new QWidget(this);
    setCentralWidget(central);

    workspaceHLayout = new QHBoxLayout(central);
    workspaceVLayout = new QVBoxLayout;
    workspaceHLayout->addLayout(workspaceVLayout);

    // file tree setup
    explorerLabel = new QLabel("Explorer");
    fileTree = new QTreeView(this);
    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath("C:/");
    fileTree->setModel(fileModel);

    fileTree->setRootIndex(
        fileModel->index("C:/")
        );

    fileTree->hideColumn(1);
    fileTree->hideColumn(2);
    fileTree->hideColumn(3);
    fileTree->setHeaderHidden(true);

    workspaceVLayout->addWidget(explorerLabel);
    workspaceVLayout->addWidget(fileTree);

    // Canvas area
    canvasArea = new QFrame;
    canvasArea->setFrameShape(QFrame::Box);
    canvasArea->setMinimumSize(400,400);

    workspaceHLayout->addWidget(canvasArea, 1);
}

GrapeW::~GrapeW()
{
    delete central;
}

void GrapeW::createSubmenus()
{

}

void GrapeW::handleOpenProject()
{

}
