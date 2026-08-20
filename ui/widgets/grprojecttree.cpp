#include "grprojecttree.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTreeView>
#include <QHeaderView>

#include "grprojecttreemodel.h"
#include "grasset.h"


GrProjectTree::GrProjectTree(QWidget *parent, QMap<AssetType, QVector<GrAsset*>> assets)
{
    // vertical layout that contains the project tree itself
    workspaceVLayout = new QVBoxLayout(this);
    QWidget* treeFrame = new QWidget(this);
    treeFrame->setObjectName("explorerContainer");
    treeFrame->setAttribute(Qt::WA_StyledBackground, true);
    QVBoxLayout* treeLayout = new QVBoxLayout(treeFrame);
    treeLayout->setContentsMargins( 8, 8, 8, 8 );
    treeLayout->setSpacing(6);
    workspaceVLayout->addWidget(treeFrame);

    // "Explorer" label above tree
    explorerLabel = new QLabel("Explorer");

    // init file tree from model
    fileModel = new GrProjectTreeModel(assets);
    fileTree = new QTreeView(this);
    fileTree->setModel(fileModel);
    fileTree->setHeaderHidden(true);
    fileTree->setAnimated(true);
    fileTree->setUniformRowHeights(true);
    fileTree->setContentsMargins( 2, 2, 2, 2 );
    fileTree->setRootIsDecorated(false);
    explorerLabel->setContentsMargins( 2, 2, 2, 2 );

    treeLayout->addWidget(explorerLabel);
    treeLayout->addWidget(fileTree);
    workspaceVLayout->setContentsMargins( 0, 0, 0, 0 );


    connect( fileTree->selectionModel(), &QItemSelectionModel::currentChanged, this, &GrProjectTree::handleSelectionChanged);
    connect(fileModel, &GrProjectTreeModel::rowsInserted, this, [=](const QModelIndex &index, int first, int last){
        fileTree->expand(index);
    });
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
