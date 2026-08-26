#ifndef GRCANVAS_H
#define GRCANVAS_H

#include <QWidget>

class GrGraphic;

class GrCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit GrCanvas(QWidget* parent = nullptr);

    void setGraphic(GrGraphic* graphic);
    void setFrameIndex(int index);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    GrGraphic* m_graphic;
    int m_currentFrame = 0;
};

#endif // GRCANVAS_H
