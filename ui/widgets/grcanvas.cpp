#include "grcanvas.h"

#include <QPainter>

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
    if (animationPaths.isEmpty())
        return;

    const QString firstKey = animationPaths.keys().constFirst();
    GrGraphic* graphic = new GrGraphic(this);
    if (!graphic->load(animationPaths.value(firstKey).v)) {
        qWarning() << "Failed to load graphic:" << animationPaths.value(firstKey).v;
        graphic->deleteLater();
        return;
    }

    setGraphic(graphic);
}

void GrCanvas::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (!m_graphic || m_graphic->frameCount() == 0)
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, false);

    const QImage frame = m_graphic->compositeFrame(m_currentFrame);
    if (frame.isNull())
        return;

    const QPoint offset = m_graphic->frameOffset(m_currentFrame);
    const int baseX = (width() - frame.width()) / 2;
    const int baseY = (height() - frame.height()) / 2;

    painter.drawImage(baseX + offset.x(), baseY + offset.y(), frame);
}

void GrCanvas::handleFrameEdited(int currentFrameId)
{
    if (currentFrameId == m_currentFrame)
        update();
}

void GrCanvas::handleGraphicLoaded()
{
    update();
}
