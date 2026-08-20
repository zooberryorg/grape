#include "grproject.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QSplitter>

#include "grpropertypanelmgr.h"
#include "grcanvasworkspace.h"

GrProject::GrProject(QWidget *parent)
    : QWidget{parent}
{
    QSplitter* hSplitter = new QSplitter(Qt::Horizontal, this);

    QHBoxLayout* projectLayout = new QHBoxLayout(this);
    projectLayout->setContentsMargins(0, 0, 0, 0);

    projectLayout->addWidget(hSplitter);

    // Canvas area
    canvasArea = new GrCanvasWorkspace(this);
    panelMgr = new GrPropertyPanelMgr(this);

    hSplitter->addWidget(canvasArea);
    hSplitter->addWidget(panelMgr);

    hSplitter->setStretchFactor(0, 1);
}

void GrProject::showAsset(GrAsset* asset) {
    panelMgr->loadAsset(asset);
}
