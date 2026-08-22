#include "grpropertypanel.h"
#include <QSpinBox>
#include <QLineEdit>
#include <QToolBar>
#include <QLayoutItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>

#include "grshared.h"
#include "grini.h"
#include "grasset.h"
#include "grcheckbox.h"
#include "grspinner.h"
#include "grlineedit.h"

using Widget = GrShared::WidgetType;

GrPropertyPanel::GrPropertyPanel(QWidget *parent, GrShared::PropertyGroup groupType)
    : QWidget{parent},
      m_group{groupType}
{
    setObjectName("propertyPanel");
    setAttribute(Qt::WA_StyledBackground, true);
    m_layout = new QVBoxLayout(this);
    m_layout->addStretch();
    m_layout->setContentsMargins( 16, 16, 16, 16 );
    m_layout->setAlignment(Qt::AlignCenter);
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
    QWidget* fieldCtr = new QWidget(parent);
    QWidget* field = nullptr;
    QVBoxLayout* layout = new QVBoxLayout(fieldCtr);
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->setSpacing(0);

    switch (value.widgetType) {
        case Widget::Integer: {
            GrSpinner* spin = new GrSpinner(fieldCtr, key);
            spin->widget()->setRange(-1000, 1000);
            spin->widget()->setValue(value.v.toInt());
            field = spin;
            break;
        }
        case Widget::Float: {
            QDoubleSpinBox* spin = new QDoubleSpinBox(fieldCtr);
            spin->setValue(value.v.toDouble());
            field = spin;
            break;
        }
        case Widget::Switch: {
            GrCheckBox* check = new GrCheckBox(fieldCtr, key);
            bool isTrue = GrINI::stringToBool(value.v).toBool();
            check->widget()->setChecked(isTrue);
            field = check;
            break;
        }
        default: {
            GrLineEdit* edit = new GrLineEdit(fieldCtr, key);
            edit->widget()->setText(value.v);
            field = edit;
            break;
        }
    }

    field->setProperty("configKey", key);
    layout->addWidget(field);
    return fieldCtr;
}
