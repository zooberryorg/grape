#include "grwelcomescreen.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

GrWelcomeScreen::GrWelcomeScreen()
{
    // -------- fonts
    QFont robotoHeader("Roboto");
    robotoHeader.setPointSize(16);
    robotoHeader.setWeight(QFont::Bold);

    QFont robotoSubheader("Roboto");
    robotoSubheader.setPointSize(12);
    robotoSubheader.setWeight(QFont::DemiBold);

    QFont robotoButton("Roboto");
    robotoButton.setPointSize(10);
    robotoButton.setWeight(QFont::Normal);


    // -------- layouts

    // -------------------- MAIN LAYOUT
    QVBoxLayout* welcomeLayout = new QVBoxLayout(this);
    welcomeLayout->setContentsMargins(32, 24, 32, 24);

    // --------------------- TITLE LAYOUT
    QVBoxLayout* titleLayout = new QVBoxLayout;
    titleLayout->setSpacing(4);

    QLabel* title = new QLabel("GrAPE", this);
    title->setFont(robotoHeader);
    title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QLabel* subtitle = new QLabel("the Great Animal Project Editor", this);
    subtitle->setFont(robotoSubheader);
    subtitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    titleLayout->addSpacing(20);

    // --------------------- COLUMNS LAYOUT
    QHBoxLayout* columnsLayout = new QHBoxLayout;
    QVBoxLayout* leftColumn = new QVBoxLayout;
    QVBoxLayout* rightColumn = new QVBoxLayout;

    QPushButton* newProject = new QPushButton("New Project", this);
    newProject->setFont(robotoButton);
    newProject->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPushButton* openProject = new QPushButton("Open", this);
    openProject->setFont(robotoButton);
    openProject->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPushButton* importProject = new QPushButton("Import", this);
    importProject->setFont(robotoButton);
    importProject->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPushButton* exitApp = new QPushButton("Exit", this);
    exitApp->setFont(robotoButton);
    exitApp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    welcomeLayout->addLayout(columnsLayout);

    columnsLayout->addLayout(leftColumn);
    columnsLayout->addLayout(rightColumn);

    // ------------------------------- LEFT COLUMN

    titleLayout->addWidget(title);
    titleLayout->addWidget(subtitle);
    leftColumn->addLayout(titleLayout);

    leftColumn->addWidget(newProject);
    leftColumn->addWidget(openProject);
    leftColumn->addWidget(importProject);
    leftColumn->addWidget(exitApp);

    // -------------------------------- RIGHT COLUMN

    QLabel* recentWorkspaces = new QLabel("Recent Workspaces");
    recentWorkspaces->setFont(robotoSubheader);
    recentWorkspaces->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QPushButton* project1 = new QPushButton("Workspace 1", this);
    project1->setFont(robotoButton);
    project1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPushButton* project2 = new QPushButton("Workspace 2", this);
    project2->setFont(robotoButton);
    project2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    rightColumn->addWidget(recentWorkspaces);
    rightColumn->addWidget(project1);
    rightColumn->addWidget(project2);

}
