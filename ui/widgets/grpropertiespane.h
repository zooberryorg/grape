#ifndef GRPROPERTIESPANE_H
#define GRPROPERTIESPANE_H

#include <QWidget>

class GrAsset;

class GrPropertiesPane : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertiesPane(QWidget *parent = nullptr);
    void loadAsset(GrAsset* asset);
    void applyToAsset();
    QWidget* createField(const QString& section, const QString& key, const QVariant& value, QWidget* parent);
private:
    struct Field {
        QString section;
        QString key;
        QWidget* widget;
        std::function<QVariant()> getValue;
    };
};

#endif // GRPROPERTIESPANE_H
