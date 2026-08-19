#include "grprojecttree.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTreeView>

#include "grprojecttreemodel.h"
#include "grasset.h"


GrProjectTree::GrProjectTree(QWidget *parent, QMap<AssetType, QVector<GrAsset*>> assets)
{
    setObjectName("explorerContainer");
    // vertical layout that contains the project tree itself
    workspaceVLayout = new QVBoxLayout(this);

    // "Explorer" label above tree
    explorerLabel = new QLabel("Explorer");

    // init file tree from model
    fileModel = new GrProjectTreeModel(assets);
    fileTree = new QTreeView(this);
    fileTree->setModel(fileModel);
    fileTree->setHeaderHidden(true);
    fileTree->setAnimated(true);
    fileTree->setUniformRowHeights(true);
    fileTree->setContentsMargins( 1, 1, 1, 1 );


    workspaceVLayout->addWidget(explorerLabel);
    workspaceVLayout->addWidget(fileTree);

    workspaceVLayout->setContentsMargins(0, 0, 0, 0);

    connect( fileTree->selectionModel(), &QItemSelectionModel::currentChanged, this, &GrProjectTree::handleSelectionChanged);
}

void GrProjectTree::insertProject(GrAsset *asset)
{
    fileModel->insertProject(asset);
}

void GrProjectTree::handleSelectionChanged(const QModelIndex &current, const QModelIndex &)
{
    if ( !current.isValid() || current.internalId() == quintptr(-1) ) {
        return;
    }

    GrAsset* asset = fileModel->data( current, Qt::UserRole ).value<GrAsset*>();
    if ( asset ) {
        emit assetSelected( asset );
    }
}
