#ifndef GRGFX_H
#define GRGFX_H

#include <QIcon>
#include <QPixmap>

namespace GrGfx
{
    QIcon setSvgColor(const QString&, const QColor&, int, int);
    QPixmap emptyMapOfSize(int width, int height);
};

#endif // GRGFX_H
