#ifndef GRPROJECTTREE_H
#define GRPROJECTTREE_H

#include <QWidget>

class QVBoxLayout;
class QTreeView;
class QFileSystemModel;
class QLabel;
class AssetType;
class GrAsset;

class GrProjectTree : public QWidget
{
    Q_OBJECT
public:
    explicit GrProjectTree(QWidget *parent = nullptr, QMap<AssetType, QVector<GrAsset*>> assets = {});

private:
    QVBoxLayout* workspaceVLayout;
    QTreeView* fileTree;
    QFileSystemModel* fileModel;
    QLabel* explorerLabel;

};

#endif // GRPROJECTTREE_H
