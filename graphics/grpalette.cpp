#include "grpalette.h"

GrPalette::GrPalette(std::shared_ptr<PalF> source, QObject *parent)
{

}

QVector<QRgb> GrPalette::palette() const
{
    QVector<QRgb> table;
    const std::vector<PalF::Color> colors = m_pal->colors();
    table.reserve(static_cast<int>(colors.size()));

    for (const PalF::Color& c : colors)
        table.append(qRgba(c.r, c.g, c.b, c.a));

    return table;
}

void GrPalette::setColor(int index, const QColor &color)
{

}

QColor GrPalette::color(int index) const
{

}

bool GrPalette::save(const QString &path)
{

}
