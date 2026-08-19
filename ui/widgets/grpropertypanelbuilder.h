#ifndef GRPROPERTYPANELBUILDER_H
#define GRPROPERTYPANELBUILDER_H

#include <QWidget>
#include <QAction>
#include "grpropertypanel.h"

class GrPropertyPanelBuilder : public QWidget
{
    Q_OBJECT
public:
    explicit GrPropertyPanelBuilder(QWidget *parent = nullptr);

signals:

};

#endif // GRPROPERTYPANELBUILDER_H
