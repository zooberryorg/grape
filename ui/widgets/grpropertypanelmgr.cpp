#include "grpropertypanelmgr.h"

#include <QActionGroup>
#include <QHBoxLayout>

#include "grasset.h"
#include "grpropertypanel.h"

static const QHash<GrShared::PropertyGroup, QString> groupIcons = {
    { GrShared::ID,       ":/icons/id.svg" },
    { GrShared::Commerce, ":/icons/coin.svg" },
};

GrPropertyPanelMgr::GrPropertyPanelMgr(QWidget *parent)
    : QWidget{parent}
{
    m_toolbar = new QToolBar;
    m_toolbar->setOrientation(Qt::Vertical);
    m_toolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    m_toolbar->setMaximumWidth(50);

    m_group = new QActionGroup(this);
    m_group->setExclusive(true);

    m_panelStack = new QStackedWidget;

    auto* layout = new QHBoxLayout(this);
    layout->addWidget(m_panelStack, 1);
    layout->addWidget(m_toolbar);
}

void GrPropertyPanelMgr::loadAsset(GrAsset *asset)
{
    // reset anything inside of the panel
    qDeleteAll(m_panels);
    qDeleteAll(m_actions);
    m_panels.clear();
    m_actions.clear();

    // only get groups with something loaded
    QSet<GrShared::PropertyGroup> populatedGroups;
    for ( GrShared::Section* section : asset->allSections() ){
        for ( const auto& key : *section ) {
            for ( const auto& value : key ) {
                if ( !value.v.isEmpty() ) {
                    populatedGroups.insert(value.group);
                }
            }
        }
    }

    for ( GrShared::PropertyGroup g : populatedGroups ) {
        auto* panel = new GrPropertyPanel(m_panelStack, g);
        panel->loadAsset(asset);
        m_panelStack->addWidget(panel);
        m_panels.insert(g, panel);

        QIcon icon = groupIcons.contains(g)
            ? GrGfx::setSvgColor(groupIcons[g], QColor("#12834b"), 50, 50)
            : QIcon();

        QAction* action = m_toolbar->addAction(icon, GrShared::GroupToString(g));
        action->setCheckable(true);
        m_group->addAction(action);
        m_actions.insert(g, action);

        connect(action, &QAction::triggered, this, [this, panel]{ m_panelStack->setCurrentWidget(panel); });
    }

    if ( !m_actions.isEmpty() ) {
        m_actions.begin().value()->setChecked(true);
        m_panelStack->setCurrentWidget(m_panels.begin().value());
    }
}
