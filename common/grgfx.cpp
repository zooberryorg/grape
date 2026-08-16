#include "grgfx.h"
#include <QSvgRenderer>

QIcon GrGfx::setSvgColor(const QString& path, int width, int height)
{
    QPixmap map = emptyMapOfSize( width, height );
}

QPixmap GrGfx::emptyMapOfSize(int width, int height)
{
    QPixmap map{ width, height };
    map.fill( Qt::transparent );
    return map;
}
