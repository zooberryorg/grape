#include "grcanvasworkspace.h"

#include <QFrame>
#include <QVBoxLayout>

GrCanvasWorkspace::GrCanvasWorkspace(QWidget* parent)
    :QWidget(parent)
{
    QVBoxLayout* workspaceLayout = new QVBoxLayout(this);
    workspaceLayout->setContentsMargins( 0, 0, 0, 0 );

    canvasArea = new QFrame;
    canvasArea->setObjectName("canvasArea");
    canvasArea->setFrameShape(QFrame::Box);

    fgLayers = new QFrame;
    fgLayers->setObjectName("canvasArea");
    fgLayers->setFrameShape(QFrame::Box);
    fgLayers->setMaximumHeight(80);

    bgLayer = new QFrame;
    bgLayer->setObjectName("canvasArea");
    bgLayer->setFrameShape(QFrame::Box);
    bgLayer->setMaximumHeight(80);

    shadowLayers = new QFrame;
    shadowLayers->setObjectName("canvasArea");
    shadowLayers->setFrameShape(QFrame::Box);
    shadowLayers->setMaximumHeight(80);

    workspaceLayout->addWidget(canvasArea);
    workspaceLayout->addWidget(fgLayers);
    workspaceLayout->addWidget(bgLayer);
    workspaceLayout->addWidget(shadowLayers);
}
