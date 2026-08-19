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
    QWidget* treeFrame = new QWidget(this);
    treeFrame->setObjectName("explorerContainer");
    treeFrame->setAttribute(Qt::WA_StyledBackground, true);
    QVBoxLayout* treeLayout = new QVBoxLayout(treeFrame);
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
    explorerLabel->setContentsMargins( 2, 2, 2, 2 );
    QWidget* versionBox = new QWidget(this);
    QLabel* version = new QLabel("GrAPE 0.1.0", versionBox);
    QVBoxLayout* versionLayout = new QVBoxLayout;
    versionBox->setLayout(versionLayout);
    versionLayout->addWidget(version);
    versionLayout->setContentsMargins( 0, 0, 0, 0 );
    versionBox->setObjectName("explorerContainer");;


    treeLayout->addWidget(explorerLabel);
    treeLayout->addWidget(fileTree);
    workspaceVLayout->addWidget(versionBox);

    workspaceVLayout->setContentsMargins(4, 4, 4, 4);


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
