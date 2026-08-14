#include "grprojecttree.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTreeView>
#include "grprojecttreemodel.h"

GrProjectTree::GrProjectTree(QWidget *parent, QMap<AssetType, QVector<GrAsset*>> assets)
{
    workspaceVLayout = new QVBoxLayout(this);
    explorerLabel = new QLabel("Explorer");
    fileTree = new QTreeView(this);
    fileModel = new GrProjectTreeModel(assets);
    fileTree->setModel(fileModel);
    fileTree->setHeaderHidden(true);

    workspaceVLayout->addWidget(explorerLabel);
    workspaceVLayout->addWidget(fileTree);
}
