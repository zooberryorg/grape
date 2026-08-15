#include "grwelcomescreen.h"

#include <QHBoxLayout>
#include <QLabel>

GrWelcomeScreen::GrWelcomeScreen()
{
    workspaceHLayout = new QHBoxLayout(this);
    workspaceVLLayout = new QVBoxLayout(this);

    newProjectLabel = new QLabel("New Project");

    workspaceHLayout->addLayout(workspaceVLLayout);
    workspaceVLLayout->addWidget(newProjectLabel);
}
