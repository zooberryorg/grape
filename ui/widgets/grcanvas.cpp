#include "grcanvas.h"

#include "grgraphic.h"
#include "grasset.h"

GrCanvas::GrCanvas(QWidget *parent)
    : QWidget{parent},
      m_graphic(nullptr)
{
    setObjectName("canvasArea");
    setAttribute(Qt::WA_StyledBackground, true);
}

void GrCanvas::setGraphic(GrGraphic *graphic)
{
    if (m_graphic)
        disconnect(m_graphic, nullptr, this, nullptr);

    m_graphic = graphic;
    m_currentFrame = 0;

    if (m_graphic) {
        connect(m_graphic, &GrGraphic::loaded, this, &GrCanvas::handleGraphicLoaded);
        connect(m_graphic, &GrGraphic::frameEdited, this, &GrCanvas::handleFrameEdited);
    }

    update();
}

void GrCanvas::setFrameIndex(int index)
{
    if (!m_graphic || index < 0 || index >= m_graphic->frameCount())
        return;

    m_currentFrame = index;
    update();
}

void GrCanvas::loadAsset(GrAsset *asset)
{
    QHash<QString, Value> animationPaths = asset->getAnimationPaths();
    for ( const GrShared::Value& path : animationPaths ) {
        GrGraphic* graphic = new GrGraphic;
        graphic->load(path.v);
        setGraphic(graphic);
    }
}

void GrCanvas::paintEvent(QPaintEvent *event)
{

}

void GrCanvas::handleFrameEdited()
{
    update();
}

void GrCanvas::handleGraphicLoaded(int currentFrameId)
{
    if (currentFrameId == m_currentFrame)
        update();
}
