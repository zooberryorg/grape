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

    appTitleLabel = new QLabel("GrAPE", this);
    appTitleLabel->setFont(robotoHeader);

    appSubtitleLabel = new QLabel("the Great Animal Project Editor", this);
    appSubtitleLabel->setFont(robotoSubheader);

    newProjectLabel = new QLabel("New Project", this);
    newProjectLabel->setFont(robotoSubheader);

    workspaceHLayout->addLayout(workspaceVLLayout);
    workspaceVLLayout->addWidget(appTitleLabel);
    workspaceVLLayout->addWidget(appSubtitleLabel);
    workspaceVLLayout->addWidget(newProjectLabel);
}
