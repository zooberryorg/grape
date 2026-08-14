#include <QSplitter>
#include <QHBoxLayout>

#include "grworkspace.h"
#include "grprojecttree.h"
#include "grasset.h"
#include "grdscanner.h"

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

void GrWorkspace::addProject(QString dir)
{
    GrDScanner scanner(dir);

    if ( projects.empty() ) {
        projects = scanner.assets();
    } else {
        for ( const auto& asset : scanner.assets() ) {
            projects.push_back(std::move(asset));
        }
    }

    if ( projects.empty() ) {
        // handle error when no files found
    }
}
