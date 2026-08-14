#include "grapew.h"
#include "grprojecttreemodel.h"
#include "grprojecttree.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&Open");

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
