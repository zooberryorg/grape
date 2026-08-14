#include "grprojecttree.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTreeView>

#include "grprojecttreemodel.h"
#include "grasset.h"


GrProjectTree::GrProjectTree(QWidget *parent, QMap<AssetType, QVector<GrAsset*>> assets)
{
    // vertical layout that contains the project tree itself
    workspaceVLayout = new QVBoxLayout(this);

    // "Explorer" label above tree
    explorerLabel = new QLabel("Explorer");

    // init file tree from model
    fileModel = new GrProjectTreeModel(assets);
    fileTree = new QTreeView(this);
    fileTree->setModel(fileModel);
    fileTree->setHeaderHidden(true);

    workspaceVLayout->addWidget(explorerLabel);
    workspaceVLayout->addWidget(fileTree);
}
