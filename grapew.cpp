#include "grapew.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    central = new QWidget(this);
    setCentralWidget(central);

    workspaceVLayout = new QVBoxLayout(central);
    workspaceHLayout = new QHBoxLayout;
    workspaceVLayout->addLayout(workspaceHLayout);

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
