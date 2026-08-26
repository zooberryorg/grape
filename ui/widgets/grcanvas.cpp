#include "grcanvas.h"

#include "grgraphic.h"

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

}

void GrCanvas::paintEvent(QPaintEvent *event)
{

}
