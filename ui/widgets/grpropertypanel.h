#ifndef GRPROPERTYPANEL_H
#define GRPROPERTYPANEL_H

#include <QWidget>
#include <QHash>
#include "grshared.h"

class GrAsset;
class QVBoxLayout;

class GrPropertyPanel : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertyPanel(QWidget *parent = nullptr, GrShared::PropertyGroup = GrShared::PropertyGroup::Misc);
    void loadAsset(GrAsset* asset);
    void applyToAsset();
    QWidget* createField(QWidget* parent, const QString& section, const QString& key, const GrShared::Value& value);
    GrShared::PropertyGroup group() { return m_group; };
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
    GrShared::PropertyGroup m_group;
};

#endif // GRPROPERTYPANEL_H
