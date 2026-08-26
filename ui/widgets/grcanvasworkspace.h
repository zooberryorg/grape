#ifndef GRCANVASWORKSPACE_H
#define GRCANVASWORKSPACE_H

#include <QWidget>

class GrAsset;
class GrCanvasWorkspace;
class QFrame;

class GrCanvasWorkspace : public QWidget
{
    Q_OBJECT
public:
    explicit GrCanvasWorkspace(QWidget* parent = nullptr, GrAsset* asset = nullptr);
private:
    GrCanvasWorkspace *canvasArea;
    QFrame *fgLayers;
    QFrame *bgLayer;
    QFrame *shadowLayers;

    GrAsset* m_asset;
};

#endif // GRCANVASWORKSPACE_H
