#ifndef GRPROPERTYPANELMGR_H
#define GRPROPERTYPANELMGR_H

#include <QWidget>
#include <QAction>
#include "grpropertypanel.h"

class GrPropertyPanelMgr : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertyPanelMgr(QWidget *parent = nullptr);

signals:
private:
    QList<GrPropertyPanel*> m_panels;
    QList<QAction*> m_actions;

};

#endif // GRPROPERTYPANELMGR_H
