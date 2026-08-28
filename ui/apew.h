#ifndef APEW_H
#define APEW_H

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

class GrWorkspace;
class GrWelcomeScreen;

QT_BEGIN_NAMESPACE
namespace Ui {
class ApeW;
}
QT_END_NAMESPACE

class ApeW : public QMainWindow
{
    Q_OBJECT

public:
    ApeW(QWidget *parent = nullptr);
    ~ApeW();

private slots:
    void handleImportProjectFromDisk();
    void handleImportProjectFromZTD();
private:
    // main containers
    QStackedWidget* central; // bg container

    // views
    GrWorkspace* workspaceScreen;
    GrWelcomeScreen* welcomeScreen;

};
#endif // APEW_H
