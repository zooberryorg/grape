#ifndef GRPROJECTTREE_H
#define GRPROJECTTREE_H

#include <QWidget>
#include "grshared.h"

class QVBoxLayout;
class QTreeView;
class QLabel;

class GrProjectTreeModel;
class GrAsset;

class GrProjectTree : public QWidget
{
    Q_OBJECT
public:
    explicit GrProjectTree(QWidget *parent = nullptr, QMap<GrShared::AssetTypes, QVector<GrAsset*>> assets = {});
    void insertProject(GrAsset* asset);

private:
    QVBoxLayout* workspaceVLayout;
    QTreeView* fileTree;
    GrProjectTreeModel* fileModel;
    QLabel* explorerLabel;

};

#endif // GRPROJECTTREE_H
