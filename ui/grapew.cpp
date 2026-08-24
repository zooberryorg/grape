#include "grapew.h"
#include "grworkspace.h"
#include "grwelcomescreen.h"
#include <QFileDialog>
#include "grzip.h"
#include <QDir>

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
    menuBar()->setNativeMenuBar(false);

    central = new QStackedWidget(this);
    central->setObjectName("centralWindow");
    setCentralWidget(central);

    welcomeScreen = new GrWelcomeScreen();
    central->addWidget(welcomeScreen);

    // initial window size
    setMinimumSize(640, 320);
    setWindowTitle("APE Studio");

    connect(openAction, &QAction::triggered, this, &GrapeW::handleImportProjectFromDisk);
    connect(fromZtdAction, &QAction::triggered, this, &GrapeW::handleImportProjectFromZTD);
    connect(welcomeScreen, &GrWelcomeScreen::importProjectRequested, this, &GrapeW::handleImportProjectFromDisk);
    connect(welcomeScreen, &GrWelcomeScreen::importProjectFromZTDRequested, this, &GrapeW::handleImportProjectFromZTD);
}

GrapeW::~GrapeW()
{
    delete central;
}

void create

void GrapeW::handleImportProjectFromDisk()
{
    QString directory = QFileDialog::getExistingDirectory(
        this,
        QFileDialog::tr("Open Project Directory"),
        QDir::homePath(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );

    GrWorkspace* workspace = new GrWorkspace;

    // TODO: handle case when dir not found here

    if ( !directory.isEmpty() && central->count() < 2 ) {

        workspace = new GrWorkspace();
        workspace->addProject(directory);

        central->addWidget(workspace);
        central->setCurrentIndex(1);

        menuBar()->setHidden(false);

        this->setMinimumSize(1024, 764);

    } else if ( !directory.isEmpty() && central->count() > 1 ) {

        workspace->addProject(directory);

    }
}

void GrapeW::handleImportProjectFromZTD()
{
    QStringList ztdFiles = QFileDialog::getOpenFileNames(
        this,
        QFileDialog::tr("Open ZTD File(s)"),
        QDir::homePath(),
        QFileDialog::tr("ZTD Files (*.ztd)")
    );

    QString tempPath = QDir::tempPath();

    for ( const QString& path : ztdFiles ) {
        GrZIP zip(path);

        if ( !zip.extractAllTo(tempPath) ) {
            // handle failure to extract here
        } else {
            GrWorkspace* workspace = new GrWorkspace;

            // TODO: handle case when dir not found here

            if ( !tempPath.isEmpty() && central->count() < 2 ) {

                workspace = new GrWorkspace();
                workspace->addProject(tempPath);

                central->addWidget(workspace);
                central->setCurrentIndex(1);

                menuBar()->setHidden(false);

                this->setMinimumSize(1024, 764);

            } else if ( !tempPath.isEmpty() && central->count() > 1 ) {

                workspace->addProject(tempPath);

            }
        }
    }
}
