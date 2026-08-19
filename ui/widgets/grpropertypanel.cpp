#include "grpropertypanel.h"
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>

#include "grshared.h"

using Widget = GrShared::WidgetType;

GrPropertyPanel::GrPropertyPanel(QWidget *parent)
    : QWidget{parent}
{

}

void GrPropertyPanel::loadAsset(GrAsset *asset)
{

}

void GrPropertyPanel::applyToAsset()
{

}

QWidget* GrPropertyPanel::createField(QWidget* parent, const QString& section, const QString& key, const GrShared::Value& value)
{
    QWidget* field = nullptr;

    switch (value.widgetType) {
        case Widget::Integer: {
            QSpinBox* spin = new QSpinBox(parent);
            spin->setRange(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
            spin->setValue(value.v.toInt());
            field = spin;
            break;
        }
        case Widget::Float: {
            QDoubleSpinBox* spin = new QDoubleSpinBox(parent);
            spin->setValue(value.v.toDouble());
            field = spin;
            break;
        }
        case Widget::Switch: {
            QCheckBox* check = new QCheckBox(parent);
            check->setChecked(value.v.toBool());
            field = check;
            break;
        }
        default: {
            QLineEdit* edit = new QLineEdit(value.v.toString(), parent);
            field = edit;
            break;
        }
    }

    field->setProperty("configKey", key);
    return field;
}
