#ifndef GRAPEW_H
#define GRAPEW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTreeView>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class GrapeW;
}
QT_END_NAMESPACE

class GrapeW : public QMainWindow
{
    Q_OBJECT

public:
    GrapeW(QWidget *parent = nullptr);
    ~GrapeW();

private slots:
    void handleOpenProject();

private:
    void createSubmenus();
    QAction openFromFiles;

    // general layout
    QWidget* central;
    QVBoxLayout* workspaceVLayout;
    QHBoxLayout* workspaceHLayout;

    // main three widgets
    QTreeView* fileTree;
    QFileSystemModel* fileModel;
};
#endif // GRAPEW_H
