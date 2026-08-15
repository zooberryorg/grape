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

    welcomeLayout = new QVBoxLayout(this);
    workspaceVLLayout = new QVBoxLayout(this);
    workspaceVLLayout->setSpacing(4);

    appTitleLabel = new QLabel("GrAPE", this);
    appTitleLabel->setFont(robotoHeader);
    appTitleLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    appSubtitleLabel = new QLabel("the Great Animal Project Editor", this);
    appSubtitleLabel->setFont(robotoSubheader);
    appSubtitleLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    workspaceVLLayout->addSpacing(20);

    newProjectLabel = new QLabel("New Project", this);
    newProjectLabel->setFont(robotoSubheader);

    welcomeLayout->addLayout(workspaceVLLayout);
    workspaceVLLayout->addWidget(appTitleLabel);
    workspaceVLLayout->addWidget(appSubtitleLabel);
    workspaceVLLayout->addWidget(newProjectLabel);
}
