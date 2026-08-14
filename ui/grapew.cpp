#include "grapew.h"
#include "grworkspace.h"
#include "grwelcomescreen.h"
#include <QFileDialog>

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    QAction* newProjectAction = fileMenu->addAction("&New Project...");
    QAction* newWindowAction = fileMenu->addAction("&New Window...");
    QAction* openAction = fileMenu->addAction("&Open...");
    QAction* saveAction = fileMenu->addAction("&Save...");

    fileMenu->addSeparator();

    QMenu* importMenu = new QMenu("&Import");
    fileMenu->addMenu(importMenu);

    QAction* fromDirAction = importMenu->addAction("&From directory...");
    QAction* fromZtdAction = importMenu->addAction("&From ZTD file...");
    QAction* exportAction = fileMenu->addAction("&Export...");

    fileMenu->addSeparator();
    QAction* closeWorkspaceAction = fileMenu->addAction("&Close Workspace...");
    QAction* exitAction = fileMenu->addAction("&Exit...");

    central = new QStackedWidget(this);
    setCentralWidget(central);

    welcomeScreen = new GrWelcomeScreen();
    central->addWidget(welcomeScreen);

    // initial window size
    setMinimumSize(640, 320);

    connect(openAction, &QAction::triggered, this, &GrapeW::handleOpenProject);
}

GrapeW::~GrapeW()
{
    delete central;
}

void GrapeW::handleOpenProject()
{
    QString directory = QFileDialog::getExistingDirectory(
        this,
        tr("Open Project Directory"),
        QDir::homePath(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );

    // TODO: handle case when dir not found here

    if ( !directory.isEmpty() && central->count() < 2) {
        workspaceScreen = new GrWorkspace();
        workspaceScreen->addProject(directory);
        central->addWidget(workspaceScreen);
        central->setCurrentIndex(1);
    } else if ( central->count() > 1 ) {
        workspaceScreen->addProject(directory);
    }

}
