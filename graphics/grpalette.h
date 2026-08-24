#ifndef GRPALETTE_H
#define GRPALETTE_H

#include <QObject>
#include <QRgb>

#include "ztalib/PalF.h"

class GrPalette : public QObject
{
    Q_OBJECT
public:
    explicit GrPalette(std::shared_ptr<PalF> source, QObject* parent = nullptr);

    QVector<QRgb> palette() const;
    void setColor(int index, const QColor& color);
    QColor color(int index) const;

    bool save(const QString& path);

signals:
    void paletteChanged();

private:
    std::shared_ptr<PalF> m_pal;
};

#endif // GRPALETTE_H
