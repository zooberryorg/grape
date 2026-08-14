#include "grapew.h"
#include "grprojecttreemodel.h"
#include "grprojecttree.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    QAction* newAction = fileMenu->addAction("&New...");
    QAction* openAction = fileMenu->addAction("&Open...");
    fileMenu->addAction("&Save...");
    fileMenu->addSeparator();
    QMenu* importMenu = new QMenu("&Import");

    fileMenu->addMenu(importMenu);

    importMenu->addAction("&From directory...");
    importMenu->addAction("&From ZTD file...");
    fileMenu->addAction("&Export...");

    central = new QStackedWidget(this);
    setCentralWidget(central);

    // initial window size
    setMinimumSize(640, 320);

    connect(openAction, &QAction::triggered, this, &GrapeW::handleOpenProject);
}

GrapeW::~GrapeW()
{
    delete central;
}

void GrapeW::createSubmenus()
{

}

void GrapeW::handleOpenProject()
{

}
