#ifndef GRGRAPHIC_H
#define GRGRAPHIC_H

#include <QObject>

#include "ztalib/ZtaF.h"

class GrPalette;

class GrGraphic : public QObject
{
    Q_OBJECT
public:
    GrGraphic(std::shared_ptr<ZtaData> data, GrPalette* palette, QObject* parent = nullptr);

    int frameCount() const { return m_indexImages.size(); }
    QImage compositeFrame(int frameIndex) const;

    void eraseAt(int frameIndex, int x, int y);

    QPoint frameOffset(int frameIndex) const;
    uint32_t speed() const { return m_data->info.speed; }

private slots:
    void handlePaletteChanged();

private:
    void decodeFrames();

    std::shared_ptr<ZtaData> m_data;
    GrPalette* m_palette;

    QVector<QImage> m_indexImages;
    QVector<QImage> m_alphaMasks;
};

#endif // GRGRAPHIC_H
