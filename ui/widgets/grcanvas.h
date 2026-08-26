#ifndef GRCANVAS_H
#define GRCANVAS_H

#include <QWidget>

class GrGraphic;
class GrAsset;

class GrCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit GrCanvas(QWidget* parent = nullptr);

    void setGraphic(GrGraphic* graphic);
    void setFrameIndex(int index);
    void loadAsset(GrAsset* asset);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    GrGraphic* m_graphic;
    int m_currentFrame = 0;

private slots:
    void handleFrameEdited(int currentFrameId);
    void handleGraphicLoaded();
};

#endif // GRCANVAS_H
