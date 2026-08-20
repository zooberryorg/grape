#ifndef GRCANVASWORKSPACE_H
#define GRCANVASWORKSPACE_H

#include <QWidget>

class QFrame;

class GrCanvasWorkspace : QWidget
{
    Q_OBJECT
public:
    GrCanvasWorkspace(QWidget* parent);
private:
    QFrame *canvasArea;
    QFrame *fgLayers;
    QFrame *bgLayer;
    QFrame *shadowLayers;
};

#endif // GRCANVASWORKSPACE_H
