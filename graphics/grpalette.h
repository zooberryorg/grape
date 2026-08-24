#ifndef GRPALETTE_H
#define GRPALETTE_H

#include <QObject>
#include <QRgb>

#include "ztalib/PalF.h"

class GrPalette : public QObject
{
    Q_OBJECT
public:
    explicit GrPalette(QObject* parent = nullptr);

    bool load(const QString& path);
    bool save(const QString& path) const;

    QVector<QRgb> palette() const;
    void setColor(int index, const QColor& color);
    QColor color(int index) const;

signals:
    void paletteChanged();

private:
    friend class GrGraphic;
    static GrPalette* load(std::shared_ptr<PalF> existing, QObject* parent = nullptr);
    std::shared_ptr<PalF> m_pal;
};

#endif // GRPALETTE_H
