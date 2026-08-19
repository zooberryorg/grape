#include "grproject.h"

#include <QFrame>
#include <QHBoxLayout>

#include "grpropertypanelmgr.h"

GrProject::GrProject(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout* projectLayout = new QHBoxLayout(this);

    // Canvas area
    canvasArea = new QFrame(this);
    canvasArea->setFrameShape(QFrame::Box);

    panelMgr = new GrPropertyPanelMgr(this);

    projectLayout->addWidget(canvasArea, 1);
    projectLayout->addWidget(panelMgr);
}
