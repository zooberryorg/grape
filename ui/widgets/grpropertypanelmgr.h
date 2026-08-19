#ifndef GRPROPERTYPANELMGR_H
#define GRPROPERTYPANELMGR_H

#include <QWidget>
#include <QAction>
#include <QToolBar>
#include <QStackedWidget>
#include "grpropertypanel.h"

class GrPropertyPanelMgr : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertyPanelMgr(QWidget *parent = nullptr);
    void loadAsset(GrAsset* asset);

signals:
private:
    QWidget* m_toolbar;
    QVBoxLayout* m_toolbarLayout;
    QActionGroup* m_group;
    QStackedWidget* m_panelStack;
    QHash<GrShared::PropertyGroup, GrPropertyPanel*> m_panels;
    QHash<GrShared::PropertyGroup, QAction*> m_actions;
    QHash<GrShared::PropertyGroup, QToolButton*> m_buttons;

};

#endif // GRPROPERTYPANELMGR_H
