#ifndef GRPROPERTYPANELMGR_H
#define GRPROPERTYPANELMGR_H

#include <QWidget>
#include <QAction>
#include <QToolBar>
#include <QStackedWidget>
#include "grpropertypanel.h"

class GrLangTableBrowser;

class GrPropertyPanelMgr : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertyPanelMgr(QWidget *parent = nullptr);
    void loadAsset(GrAsset* asset);
    void setLangBrowserSource(GrLangTableBrowser* source) { m_langBrowserSource = source; };
    GrLangTableBrowser* getLangBrowserSource() { return m_langBrowserSource; };

signals:
private:
    QWidget* m_toolbar;
    QVBoxLayout* m_toolbarLayout;
    QActionGroup* m_group;
    QStackedWidget* m_panelStack;
    QHash<GrShared::PropertyGroup, GrPropertyPanel*> m_panels;
    QHash<GrShared::PropertyGroup, QAction*> m_actions;
    QHash<GrShared::PropertyGroup, QToolButton*> m_buttons;
    GrLangTableBrowser* m_langBrowserSource;

    GrAsset *m_currentAsset;
    void showGroup(GrShared::PropertyGroup group);
};

#endif // GRPROPERTYPANELMGR_H
