#include <QSplitter>
#include <QHBoxLayout>

#include "grworkspace.h"
#include "grprojecttree.h"

GrWorkspace::GrWorkspace(QWidget *parent)
    : QWidget{parent}
{
    workspaceHLayout = new QHBoxLayout(parent);
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
