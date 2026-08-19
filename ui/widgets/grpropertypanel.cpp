#include "grpropertypanel.h"
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QToolBar>

#include "grshared.h"
#include "grini.h"

using Widget = GrShared::WidgetType;

GrPropertyPanel::GrPropertyPanel(QWidget *parent, GrShared::PropertyGroup groupType)
    : QWidget{parent},
      m_group{groupType}
{
    // toolbar (right sidebar)
    QToolBar* toolbar = new QToolBar;
    toolbar->setOrientation(Qt::Vertical);
    toolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    toolbar->setMaximumWidth(50);

    QActionGroup* group = new QActionGroup(this);
    group->setExclusive(true);

    QAction* idTab = toolbar->addAction(
        GrGfx::setSvgColor(":/icons/id.svg", QColor("#12834b"), 50, 50),
        "ID Settings"
    );
    idTab->setCheckable(true);
    group->addAction(idTab);

    QAction* moneyTab = toolbar->addAction(
        GrGfx::setSvgColor(":/icons/coin.svg", QColor("#12834b"), 50, 50),
        "Finance Settings"
    );
    moneyTab->setCheckable(true);
    group->addAction(moneyTab);

    QWidget* toolbarFrame = new QWidget(this);
    QHBoxLayout* toolbarLayout = new QHBoxLayout(toolbarFrame);
    QVBoxLayout* configLayout = new QVBoxLayout();

    toolbarLayout->addWidget(toolbar);
    toolbarLayout->addLayout(configLayout);

    QWidget* placeholder = new QWidget(toolbarFrame);
    configLayout->addWidget(placeholder);
    placeholder->setMinimumWidth(200);

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
