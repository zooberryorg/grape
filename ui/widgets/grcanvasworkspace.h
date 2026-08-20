#ifndef GRCANVASWORKSPACE_H
#define GRCANVASWORKSPACE_H

#include <QWidget>

class QFrame;

class GrCanvasWorkspace : public QWidget
{
    Q_OBJECT
public:
    explicit GrCanvasWorkspace(QWidget* parent = nullptr);
private:
    QFrame *canvasArea;
    QFrame *fgLayers;
    QFrame *bgLayer;
    QFrame *shadowLayers;
};

#endif // GRCANVASWORKSPACE_H
