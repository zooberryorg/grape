#include "grpalette.h"

#include <QColor>

GrPalette::GrPalette(QObject *parent)
    : QObject(parent),
      m_pal(std::move(source))
{

}

GrPalette::GrPalette(QObject *parent)
{

}

bool GrPalette::load(const QString &path)
{

}

bool GrPalette::save(const QString &path) const
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
    std::vector<PalF::Color> colors = m_pal->colors();
    if (index < 0 || index >= static_cast<int>(colors.size()))
        return;

    colors[index] = PalF::Color{
        static_cast<uint8_t>(color.red()),
        static_cast<uint8_t>(color.green()),
        static_cast<uint8_t>(color.blue()),
        static_cast<uint8_t>(color.alpha())
    };
    m_pal->colors(colors);

    emit paletteChanged();
}

QColor GrPalette::color(int index) const
{
    const PalF::Color c = const_cast<PalF*>(m_pal.get())->getColor(index);
    return QColor(c.r, c.g, c.b, c.a);
}

GrPalette *GrPalette::load(std::shared_ptr<PalF> existing, QObject *parent)
{

}

bool GrPalette::save(const QString &path)
{
    m_pal->save(path.toStdString());
    return true;
}
