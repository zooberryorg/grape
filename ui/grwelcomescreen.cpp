#include "grwelcomescreen.h"

#include <QHBoxLayout>
#include <QLabel>

GrWelcomeScreen::GrWelcomeScreen()
{
    QFont robotoHeader("Roboto");
    robotoHeader.setPointSize(16);
    robotoHeader.setWeight(QFont::Bold);

    QFont robotoSubheader("Roboto");
    robotoSubheader.setPointSize(12);
    robotoSubheader.setWeight(QFont::DemiBold);

    workspaceHLayout = new QHBoxLayout(this);
    workspaceVLLayout = new QVBoxLayout(this);

    newProjectLabel = new QLabel("New Project", this);
    newProjectLabel->setFont(robotoSubheader);

    workspaceHLayout->addLayout(workspaceVLLayout);
    workspaceVLLayout->addWidget(newProjectLabel);
}
