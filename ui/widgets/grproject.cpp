#include "grproject.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QSplitter>

#include "grpropertypanelmgr.h"
#include "grcanvasworkspace.h"
#include "grlangtablebrowser.h"

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

    for (int i = 1; i < hSplitter->count(); ++i)
        hSplitter->handle(i)->setAttribute(Qt::WA_Hover, true);
}

void GrProject::showAsset(GrAsset* asset) {
    panelMgr->loadAsset(asset);
    canvasArea->loadAsset(asset);
}

void GrProject::setLangBrowserSource(GrLangTableBrowser *source)
{
    panelMgr->setLangBrowserSource(source);
}
