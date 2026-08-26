#include "grgraphic.h"
#include "ztalib/ZtaF.h"
#include "grpalette.h"

#include <QImage>

GrGraphic::GrGraphic(QObject *parent)
    : QObject(parent),
      m_ztaF(std::make_unique<ZtaF>()),
      m_palette(nullptr)
{
}

bool GrGraphic::load(const QString &path, GrPalette *palette, const QString &paletteOverridePath)
{
    std::shared_ptr<ZtaData> data = m_ztaF->load(
        path.toStdString(), 0, paletteOverridePath.toStdString()
    );
    if (!data)
        return false;

    m_data = std::move(data);

    if (m_palette)
        disconnect(m_palette, &GrPalette::paletteChanged, this, &GrGraphic::handlePaletteChanged);

    // if palette provided, set as shared palette
    // todo: instead, create a parameter where the user can choose to make a shared palette or generate
    // one per graphic
    if (palette) {
        m_data->palette = palette->shared_palette();
        m_palette = palette;
    } else { // else, load the palette loaded by ZtaF
        m_palette = GrPalette::load(m_data->palette, this);
    }

    connect(m_palette, &GrPalette::paletteChanged, this, &GrGraphic::handlePaletteChanged);

    decode();
    emit loaded();
    return true;
}

bool GrGraphic::save(const QString &path, const QString &projectRoot, const QString &palettePath)
{
    return true;
}

QImage GrGraphic::compositeFrame(int frameIndex) const
{
    if (frameIndex < 0 || frameIndex >= m_indexImages.size())
        return QImage();

    QImage result = m_indexImages[frameIndex].convertToFormat(QImage::Format_ARGB32);
    // applies the eraser mask wherever mask is 0, forces alpha to 0
    const QImage& mask = m_alphaMasks[frameIndex];

    for (int y = 0; y < result.height(); ++y) {
        QRgb* line = reinterpret_cast<QRgb*>(result.scanLine(y));
        const uchar* maskLine = mask.scanLine(y);

        for (int x = 0; x < result.width(); ++x) {
            if (maskLine[x] == 0)
                line[x] = qRgba(0, 0, 0, 0);
        }
    }

    return result;
}

void GrGraphic::eraseAt(int frameIndex, int x, int y)
{
    if (frameIndex < 0 || frameIndex >= m_alphaMasks.size())
        return;

    QImage& mask = m_alphaMasks[frameIndex];
    if (x < 0 || x >= mask.width() || y < 0 || y >= mask.height())
        return;

    mask.scanLine(y)[x] = 0;
}

QPoint GrGraphic::frameOffset(int frameIndex) const
{
    if (frameIndex < 0 || frameIndex >= m_data->frames.size())
        return QPoint();
    return QPoint(m_data->frames[frameIndex].x, m_data->frames[frameIndex].y);
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
