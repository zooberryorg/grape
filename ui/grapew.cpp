#include "grapew.h"
#include "grprojecttreemodel.h"
#include "grprojecttree.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&New...");
    fileMenu->addAction("&Open...");
    QMenu* importMenu = fileMenu->addMenu("&Import");

    fileMenu->addAction("&From directory...");
    fileMenu->addAction("&From ZTD file...");


    central = new QStackedWidget(this);
    setCentralWidget(central);

    // initial window size
    setMinimumSize(640, 320);
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
