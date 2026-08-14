#ifndef GRPROJECTTREE_H
#define GRPROJECTTREE_H

#include <QWidget>
#include "grshared.h"
#include "grasset.h"
#include "grprojecttreemodel.h"

class QVBoxLayout;
class QTreeView;
class QFileSystemModel;
class QLabel;

class GrProjectTree : public QWidget
{
    Q_OBJECT
public:
    explicit GrProjectTree(QWidget *parent = nullptr, QMap<AssetType, QVector<GrAsset*>> assets = {});

private:
    QVBoxLayout* workspaceVLayout;
    QTreeView* fileTree;
    GrProjectTreeModel* fileModel;
    QLabel* explorerLabel;

};

#endif // GRPROJECTTREE_H
