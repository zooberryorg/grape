#include "grgfx.h"
#include <QSvgRenderer>
#include <QColor>
#include <QDebug>
#include <QPainter>

namespace GrGfx
{

    QIcon setSvgColor(const QString& path, const QColor& color, int width, int height)
    {
        QSvgRenderer renderer( path );
        if ( !renderer.isValid() ) {
            qWarning() << "Invalid SVG file:" << path;
            return QIcon();
        }

        QPixmap map = emptyMapOfSize( width, height );

        QPainter painter( &map );
        painter.setRenderHint( QPainter::Antialiasing );
        renderer.render( &painter );

        painter.setCompositionMode( QPainter::CompositionMode_SourceIn );
        painter.fillRect( map.rect(), color );
        painter.end();

        return QIcon( map );}

    QPixmap emptyMapOfSize(int width, int height)
    {
        QPixmap map{ width, height };
        map.fill( Qt::transparent );
        return map;
    }

    QGraphicsDropShadowEffect *shadowFx()
    {
        QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
        shadowEffect->setBlurRadius(4);
        shadowEffect->setColor(QColor(0, 0, 0, 140));
        shadowEffect->setOffset(0, 2);

        return shadowEffect;
    }

}
