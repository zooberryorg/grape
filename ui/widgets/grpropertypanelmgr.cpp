#include "grpropertypanelmgr.h"

#include <QActionGroup>
#include <QHBoxLayout>
#include <QToolButton>

#include "grasset.h"
#include "grpropertypanel.h"

using Group = GrShared::PropertyGroup;

static const QHash<GrShared::PropertyGroup, QString> groupIcons = {
    { Group::ID, ":/icons/id.svg" },
    { Group::Commerce, ":/icons/coin.svg" },
    { Group::Sounds, ":/icons/playlist.svg" },
    { Group::Social, ":/icons/heart.svg" },
    { Group::BehaviorSets, ":/icons/analyze.svg" },
    { Group::Exhibit, ":/icons/layout-dashboard.svg" },
    { Group::Graphics, ":/icons/box-multiple.svg" },
    { Group::Guests, ":/icons/person.svg" },
    { Group::Keepers, ":/icons/hat.svg" },
    { Group::Needs, ":/icons/paw.svg" },
    { Group::Prey, ":/icons/pig.svg" },
    { Group::Slots, ":/icons/building-2.svg" },
    { Group::Terrain, ":/icons/mountain.svg" },
    { Group::Traits, ":/icons/sparkles.svg" },
    { Group::UI, ":/icons/ui.svg" },
    { Group::Misc, ":/icons/misc.svg" },
};

GrPropertyPanelMgr::GrPropertyPanelMgr(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("propertyPanelGroup");
    setAttribute(Qt::WA_StyledBackground, true);

    m_toolbar = new QWidget(this);
    m_toolbar->setFixedWidth(30);
    m_toolbar->setObjectName("toolbar");
    m_toolbar->setAttribute(Qt::WA_StyledBackground, true);

    QHBoxLayout* toolbarHSpace = new QHBoxLayout(m_toolbar);
    toolbarHSpace->setContentsMargins( 0, 0, 0, 0 );
    m_toolbarLayout = new QVBoxLayout;
    m_toolbarLayout->setContentsMargins( 0, 0, 0, 0 );
    m_toolbarLayout->setSpacing(0);
    m_toolbarLayout->addStretch();

    toolbarHSpace->addStretch();
    toolbarHSpace->addLayout(m_toolbarLayout);

    m_group = new QActionGroup(this);
    m_group->setExclusive(true);

    m_panelStack = new QStackedWidget;

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_toolbar);
    layout->addWidget(m_panelStack, 1);
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->setSpacing(0);

}

void GrPropertyPanelMgr::loadAsset(GrAsset *asset)
{
    // reset anything inside of the panel
    qDeleteAll(m_panels);
    qDeleteAll(m_buttons);
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
        GrPropertyPanel* panel = new GrPropertyPanel(m_panelStack, g);
        panel->loadAsset(asset);
        m_panelStack->addWidget(panel);
        m_panels.insert(g, panel);

        // if dll files were loaded, ensure source is installed in every panel
        if ( m_langBrowserSource ) {
            panel->setLangBrowserSource(m_langBrowserSource);
        }

        QIcon icon = groupIcons.contains(g)
            ? GrGfx::setSvgColor(groupIcons[g], QColor("#c2c6c0"), 50, 50)
            : QIcon();

        QAction* action = m_toolbar->addAction(icon, GrShared::GroupToString(g));
        action->setCheckable(true);
        m_group->addAction(action);
        m_actions.insert(g, action);

        // make the buttons
        QToolButton* button = new QToolButton(m_toolbar);
        button->setDefaultAction(action);
        button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        button->setFixedSize(28, 30);
        button->setObjectName("toolbarButton");
        m_toolbarLayout->insertWidget(m_toolbarLayout->count() - 1, button);
        m_buttons.insert(g, button);

        connect(action, &QAction::triggered, this, [this, panel]{ m_panelStack->setCurrentWidget(panel); });
    }

    if ( !m_actions.isEmpty() ) {
        m_actions.begin().value()->setChecked(true);
        m_panelStack->setCurrentWidget(m_panels.begin().value());
    }
}
