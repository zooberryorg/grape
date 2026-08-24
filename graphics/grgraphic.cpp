#include "grgraphic.h"
#include "ztalib/ZtaF.h"
#include "grpalette.h"

#include <QImage>

GrGraphic::GrGraphic(QObject *parent)
    : QObject(parent),
      m_ztaF(std::make_unique<ZtaF>()),
      m_palette(nullptr)
{
    connect(m_palette, &GrPalette::paletteChanged, this, &GrGraphic::handlePaletteChanged);
    decode();
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
    const QVector<QRgb> palette = m_palette->palette();
    for (QImage& img : m_indexImages) {
        img.setColorTable(palette);
    }
}

void GrGraphic::decode()
{
    m_indexImages.clear();
    m_alphaMasks.clear();

    const QVector<QRgb> table = m_palette->palette();

    for (const ZtaFrame& frame : m_data->frames) {
        QImage indexImg(frame.width, frame.height, QImage::Format_Indexed8);
        indexImg.setColorTable(table);
        indexImg.fill(0);

        QImage mask(frame.width, frame.height, QImage::Format_Alpha8);
        mask.fill(0);

        for (int row = 0; row < frame.height && row < static_cast<int>(frame.pixelSets.size()); ++row) {
            const ZtaPixelSet& pixelSet = frame.pixelSets[row];
            int xPos = 0;

            uchar* indexLine = indexImg.scanLine(row);
            uchar* maskLine = mask.scanLine(row);

            for (const ZtaPixelBlock& block : pixelSet.blocks) {
                xPos += block.offset;
                if (block.colorCount == 0)
                    continue;

                for (uint8_t colorIndex : block.colors) {
                    if (xPos >= frame.width)
                        break;

                    indexLine[xPos] = colorIndex;
                    maskLine[xPos] = 255;
                    ++xPos;
                }
            }
        }

        m_indexImages.append(indexImg);
        m_alphaMasks.append(mask);
    }
}
