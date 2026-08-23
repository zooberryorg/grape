#include "grapew.h"
#include "grworkspace.h"
#include "grwelcomescreen.h"
#include <QFileDialog>
#include "grslots.h"

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

    menuBar()->setHidden(true);

    central = new QStackedWidget(this);
    central->setObjectName("centralWindow");
    setCentralWidget(central);

    welcomeScreen = new GrWelcomeScreen();
    central->addWidget(welcomeScreen);

    // initial window size
    setMinimumSize(640, 320);
    setWindowTitle("APE Studio");

    connect(openAction, &QAction::triggered, this, &GrapeW::handleOpenProject);
    connect(fromZtdAction, &QAction::triggered, this, &GrapeW::handleImportFromZTD);
    connect(welcomeScreen, &GrWelcomeScreen::openProjectRequested, this, &GrapeW::handleOpenProject);
}

GrapeW::~GrapeW()
{
    delete central;
}

void GrapeW::handleOpenProject()
{
    GrSlots::handleProjectOpen(this, central, new GrWorkspace, menuBar());
}
