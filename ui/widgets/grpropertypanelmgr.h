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
    QToolBar* m_toolbar;
    QActionGroup* m_group;
    QStackedWidget* m_panelStack;
    QHash<GrShared::PropertyGroup, GrPropertyPanel*> m_panels;
    QHash<GrShared::PropertyGroup, QAction*> m_actions;

};

#endif // GRPROPERTYPANELMGR_H
