#include "grcanvasworkspace.h"

#include <QFrame>
#include <QVBoxLayout>

GrCanvasWorkspace::GrCanvasWorkspace(QWidget* parent)
{
    QVBoxLayout* workspaceLayout = new QVBoxLayout(parent);

    canvasArea = new QFrame(this);
    canvasArea->setObjectName("canvasArea");
    canvasArea->setFrameShape(QFrame::Box);

    fgLayers = new QFrame(this);
    fgLayers->setObjectName("fgLayerWidget");
    fgLayers->setFrameShape(QFrame::Box);

    bgLayer = new QFrame(this);
    bgLayer->setObjectName("bgLayerWidget");
    bgLayer->setFrameShape(QFrame::Box);

    shadowLayers = new QFrame(this);
    shadowLayers->setObjectName("shadowLayerWidget");
    shadowLayers->setFrameShape(QFrame::Box);

    workspaceLayout->addWidget(canvasArea);
    workspaceLayout->addWidget(fgLayers);
    workspaceLayout->addWidget(bgLayer);
    workspaceLayout->addWidget(shadowLayers);
}
