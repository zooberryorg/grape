#ifndef GRAPEW_H
#define GRAPEW_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QTreeView>
#include <QFileSystemModel>
#include <QLabel>
#include <QFrame>
#include <QSplitter>
#include <QStackedWidget>

class GrProjectTree;
class GrWelcomeScreen;

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
    // main containers
    QStackedWidget* central; // bg container

    // views
    GrProjectTree* projectTree;
    GrWelcomeScreen* welcomeScreen;
};
#endif // GRAPEW_H
