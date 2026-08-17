#include "grpropertiespane.h"
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>

GrPropertiesPane::GrPropertiesPane(QWidget *parent)
    : QWidget{parent}
{

}

void GrPropertiesPane::loadAsset(GrAsset *asset)
{

}

void GrPropertiesPane::applyToAsset()
{

}

QWidget* GrPropertiesPane::createField(const QString& section, const QString& key, const QVariant& value, QWidget* parent)
{
    QWidget* field = nullptr;

    switch (value.typeId()) {
        case QMetaType::Int: {
            QSpinBox* spin = new QSpinBox(parent);
            spin->setRange(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
            spin->setValue(value.toInt());
            field = spin;
            break;
        }
        case QMetaType::Double: {
            QDoubleSpinBox* spin = new QDoubleSpinBox(parent);
            spin->setValue(value.toDouble());
            field = spin;
            break;
        }
        case QMetaType::Bool: {
            QCheckBox* check = new QCheckBox(parent);
            check->setChecked(value.toBool());
            field = check;
            break;
        }
        default: {
            QLineEdit* edit = new QLineEdit(value.toString(), parent);
            field = edit;
            break;
        }
    }

    field->setProperty("configKey", configKey);
    return field;
}
