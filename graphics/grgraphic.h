#ifndef GRGRAPHIC_H
#define GRGRAPHIC_H

#include <QObject>

#include "ztalib/ZtaF.h"

class GrPalette;

class GrGraphic : public QObject
{
    Q_OBJECT
public:
    GrGraphic(QObject* parent = nullptr);

    bool load(const QString& path, GrPalette* palette = nullptr, const QString& paletteOverridePath = "");
    bool save(const QString& path, const QString& projectRoot, const QString& palettePath);

    int frameCount() const { return m_indexImages.size(); }
    QImage compositeFrame(int frameIndex) const;

    void eraseAt(int frameIndex, int x, int y);

    QPoint frameOffset(int frameIndex) const;
    uint32_t speed() const { return m_data->info.speed; }
    GrPalette* palette() const { return m_palette; }

signals:
    void loaded();
    void frameEdited(int frameIndex);

private slots:
    void handlePaletteChanged();

private:
    void decode();

    std::unique_ptr<ZtaF> m_ztaF;
    std::shared_ptr<ZtaData> m_data;
    GrPalette* m_palette;

    QVector<QImage> m_indexImages;
    QVector<QImage> m_alphaMasks;
};

#endif // GRGRAPHIC_H
