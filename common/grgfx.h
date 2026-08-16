#ifndef GRGFX_H
#define GRGFX_H

#include <QIcon>
#include <QPixmap>

namespace GrGfx
{
    static QIcon setSvgColor(const QString&, int, int);
    QPixmap emptyMapOfSize(int width, int height);
};

#endif // GRGFX_H
