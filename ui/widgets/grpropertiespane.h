#ifndef GRPROPERTIESPANE_H
#define GRPROPERTIESPANE_H

#include <QWidget>
#include <QHash>
#include "grshared.h"

class GrAsset;
class QVBoxLayout;

class GrPropertiesPane : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertiesPane(QWidget *parent = nullptr);
    void loadAsset(GrAsset* asset);
    void applyToAsset();
    QWidget* createField(const GrShared::Property& property, QWidget* parent);
private:
    struct Field {
        QString section;
        QString key;
        QWidget* widget;
        std::function<QVariant()> getValue;
    };
    QHash<QString, QHash<QString, Field>> m_fields;
    GrAsset* m_assignedAsset = nullptr;
    QVBoxLayout* m_layout;
};

#endif // GRPROPERTIESPANE_H
