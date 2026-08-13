#include "grapew.h"
#include "grprojecttreemodel.h"
#include "grprojecttree.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&Open");

    central = new QWidget(this);
    setCentralWidget(central);
    workspaceHLayout = new QHBoxLayout(central);
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
