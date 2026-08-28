#include "grpropertypanel.h"
#include <QSpinBox>
#include <QLineEdit>
#include <QToolBar>
#include <QLayoutItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QTabWidget>
#include <QScrollArea>
#include <QScrollBar>

#include "grshared.h"
#include "grini.h"
#include "grasset.h"
#include "grcheckbox.h"
#include "grspinner.h"
#include "grlineedit.h"
#include "gridselector.h"

using Widget = GrShared::WidgetType;

GrPropertyPanel::GrPropertyPanel(QWidget *parent, GrShared::PropertyGroup groupType)
    : QWidget{parent},
      m_group{groupType},
      m_langBrowserSource{nullptr}
{
    setObjectName("propertyPanel");
    setAttribute(Qt::WA_StyledBackground, true);
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(16, 16, 16, 16);
}

void GrPropertyPanel::loadAsset(GrAsset* asset, const QString& subtype)
{
    m_assignedAsset = asset;
    m_fields.clear();

    QVBoxLayout* contentLayout;

    if (!m_scrollArea) {
        m_scrollArea = new QScrollArea(this);
        m_scrollArea->setWidgetResizable(true);
        m_scrollArea->setFrameShape(QFrame::NoFrame);
        m_scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        m_scrollArea->setObjectName("propertyPanelScroll");
        m_scrollArea->viewport()->setObjectName("propertyPanelViewport");
        m_scrollArea->verticalScrollBar()->setSingleStep(20);

        m_scrollContent = new QWidget(m_scrollArea);
        m_scrollContent->setObjectName("propertyPanelContent");
        contentLayout = new QVBoxLayout(m_scrollContent);
        contentLayout->addStretch();
        contentLayout->setContentsMargins( 16, 16, 16, 16 );
        contentLayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

        m_scrollArea->setWidget(m_scrollContent);
        m_layout->addWidget(m_scrollArea);
    } else {
        contentLayout = qobject_cast<QVBoxLayout*>(m_scrollContent->layout());
        QLayoutItem* item;
        while ( contentLayout->count() > 1 && ( item = contentLayout->takeAt(0) ) ) {
            delete item->widget();
            delete item;
        }
    }

    for ( GrShared::SubtypeSections* subtypeSections : asset->allSections() ) {
        const GrShared::Section& section = subtypeSections->value(subtype);

        for ( auto sIt = section.constBegin(); sIt != section.constEnd(); ++sIt ) {
            const QString& sectionName = sIt.key();
            const GrShared::Key& key = sIt.value();

            for ( auto kIt = key.constBegin(); kIt != key.constEnd(); ++kIt ) {
                const GrShared::Value& value = kIt.value();
                if ( value.group != m_group ) continue;

                QWidget* field = createField( m_scrollContent, sectionName, kIt.key(), value );
                contentLayout->insertWidget(contentLayout->count() - 1, field);
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

GrPropertyPanel* GrPropertyPanel::buildPanelForAsset(GrAsset* asset, GrShared::PropertyGroup group, QWidget* parent)
{
    GrPropertyPanel* container = new GrPropertyPanel(parent, group);
    const auto subs = asset->subtypes();
    const bool isSingleUnprefixedType = (subs.size() == 1 && subs.first().prefix.isEmpty());

    if (isSingleUnprefixedType) {
        container->loadAsset(asset, "");
        return container;
    }

    bool hasCommonSection = false;
    for (GrShared::SubtypeSections* subtypeSections : asset->allSections()) {
        if (!subtypeSections->contains("")) continue;
        for (const GrShared::Key& key : subtypeSections->value("")) {
            if (key.isEmpty()) continue;
            if (key.constBegin().value().group == group) { hasCommonSection = true; break; }
        }
        if (hasCommonSection) break;
    }

    bool hasCommonFields = false;
    for (GrShared::SubtypeSections* subtypeSections : asset->allSections()) {
        for (const GrShared::Key& key : subtypeSections->value("")) {
            for (const auto& value : key) {
                if (value.group == group) { hasCommonFields = true; break; }
            }
            if (hasCommonFields) break;
        }
        if (hasCommonFields) break;
    }

    QTabWidget* tabs = new QTabWidget(container);

    if (hasCommonFields) {
        GrPropertyPanel* allPanel = new GrPropertyPanel(tabs, group);
        allPanel->loadAsset(asset, "");
        tabs->addTab(allPanel, "All");
    }

    for (const auto& sub : subs) {
        GrPropertyPanel* tabPanel = new GrPropertyPanel(tabs, group);
        tabPanel->loadAsset(asset, sub.prefix);
        tabs->addTab(tabPanel, sub.label);
    }

    container->setTabWidget(tabs);
    return container;
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
        case Widget::IdPicker: {
            if ( m_langBrowserSource ) {
                GrIdSelector* idSelector = new GrIdSelector(fieldCtr, key, "", m_langBrowserSource);
                idSelector->widget()->setText(value.v);
                field = idSelector;
                break;
            }
            // else, use default
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

void GrPropertyPanel::setTabWidget(QTabWidget* tabs)
{
    QLayoutItem* item;
    while ( m_layout->count() > 1 && ( item = m_layout->takeAt(0) ) ) {
        delete item->widget();
        delete item;
    }
    m_fields.clear();

    m_tabs = tabs;
    m_tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    m_layout->insertWidget(m_layout->count() - 1, m_tabs);
}
