#include "grpropertypanelmgr.h"


GrPropertyPanelMgr::GrPropertyPanelMgr(QWidget *parent)
    : QWidget{parent}
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


}
