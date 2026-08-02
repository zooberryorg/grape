#include "grapew.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    central = new QWidget(this);
    setCentralWidget(central);
    workspaceHLayout = new QHBoxLayout(central);
    hSplitter = new QSplitter;
    workspaceHLayout->addWidget(hSplitter);

    // file tree setup
    leftBarPanel = new QWidget;
    workspaceVLayout = new QVBoxLayout(leftBarPanel);
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

    hSplitter->addWidget(leftBarPanel);
    hSplitter->addWidget(canvasArea);
    hSplitter->setSizes({250, 750});

    // initial window size
    setMinimumSize(640, 320);
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
