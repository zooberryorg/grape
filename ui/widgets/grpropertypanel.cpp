#include "grpropertypanel.h"
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QToolBar>
#include <QLayoutItem>
#include <QVBoxLayout>

#include "grshared.h"
#include "grini.h"
#include "grasset.h"

using Widget = GrShared::WidgetType;

GrPropertyPanel::GrPropertyPanel(QWidget *parent, GrShared::PropertyGroup groupType)
    : QWidget{parent},
      m_group{groupType}
{
    m_layout = new QVBoxLayout(this);

    QWidget* toolbarFrame = new QWidget(this);
    QVBoxLayout* configLayout = new QVBoxLayout();

    QWidget* placeholder = new QWidget(toolbarFrame);
    configLayout->addWidget(placeholder);
    placeholder->setMinimumWidth(200);

}

void GrPropertyPanel::loadAsset(GrAsset* asset)
{
    m_assignedAsset = asset;
    m_fields.clear();

    QLayoutItem* item;
    while ( m_layout->count() > 1 && ( item = m_layout->takeAt(0) ) ) {
        delete item->widget();
        delete item;
    }

    for ( GrShared::Section* section : asset->allSections() ) {
        for ( auto sIt = section->constBegin(); sIt != section->constEnd(); ++sIt ) {
            const QString& sectionName = sIt.key();
            const GrShared::Key& key = sIt.value();

            for ( auto kIt = key.constBegin(); kIt != key.constEnd(); ++kIt ) {
                const GrShared::Value& value = kIt.value();

                if ( value.group != m_group )
                    continue;
                if ( value.v.isEmpty() )
                    continue;

                QWidget* field = createField( this, sectionName, kIt.key(), value );
                m_layout->insertWidget(m_layout->count() - 1, field);
                m_fields[sectionName][kIt.key()] = { sectionName, kIt.key(), field,
                    [field, type = value.widgetType]() ->
                        QVariant {
                            return QVariant();
                    }
                };
            }
        }
    }
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
            spin->setRange(-1000, 1000);
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
            bool isTrue = GrINI::stringToBool(value.v).toBool();
            check->setChecked(isTrue);
            field = check;
            break;
        }
        default: {
            QLineEdit* edit = new QLineEdit(value.v, parent);
            field = edit;
            break;
        }
    }

    field->setProperty("configKey", key);
    return field;
}
