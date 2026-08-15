#include "grslots.h"
#include <QString>
#include <QFileDialog>
#include <QWidget>
#include "grworkspace.h"
#include <QStackedWidget>
#include <QMenuBar>

GrSlots::GrSlots()
{

}

void GrSlots::handleProjectOpen(QWidget* parent, QStackedWidget* stackedLayouts, GrWorkspace* workspace, QMenuBar* menuBar)
{
    QString directory = QFileDialog::getExistingDirectory(
        parent,
        QFileDialog::tr("Open Project Directory"),
        QDir::homePath(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );

    // TODO: handle case when dir not found here

    if ( !directory.isEmpty() && stackedLayouts->count() < 2 ) {

        workspace = new GrWorkspace();
        workspace->addProject(directory);

        stackedLayouts->addWidget(workspace);
        stackedLayouts->setCurrentIndex(1);

        menuBar->setHidden(false);

    } else if ( !directory.isEmpty() && stackedLayouts->count() > 1 ) {

        workspace->addProject(directory);

    }

}
