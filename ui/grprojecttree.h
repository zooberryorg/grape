#ifndef GRPROJECTTREE_H
#define GRPROJECTTREE_H

#include <QWidget>

class QVBoxLayout;
class QTreeView;
class QFileSystemModel;
class QLabel;

class GrProjectTree : public QWidget
{
    Q_OBJECT
public:
    explicit GrProjectTree(QWidget *parent = nullptr);

private:
    QVBoxLayout* workspaceVLayout;
    QTreeView* fileTree;
    QFileSystemModel* fileModel;
    QLabel* explorerLabel;

};

#endif // GRPROJECTTREE_H
