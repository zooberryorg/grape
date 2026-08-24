#include "grgraphic.h"
#include "ztalib/ZtaF.h"
#include "grpalette.h"

GrGraphic::GrGraphic(std::shared_ptr<ZtaData> data, GrPalette *palette, QObject *parent)
{
    connect(m_palette, &GrPalette::paletteChanged, this, &GrGraphic::handlePaletteChanged);
    decodeFrames();
}

QImage GrGraphic::compositeFrame(int frameIndex) const
{

}

void GrGraphic::eraseAt(int frameIndex, int x, int y)
{

}

QPoint GrGraphic::frameOffset(int frameIndex) const
{

}

void GrGraphic::handlePaletteChanged()
{

}

void GrGraphic::decodeFrames()
{

}
