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
    welcomeLayout->setSpacing(20);

    // --------------------- TITLE LAYOUT
    QVBoxLayout* titleLayout = new QVBoxLayout;
    titleLayout->setSpacing(4);

    QLabel* title = new QLabel("APE Studio", this);
    title->setFont(robotoHeader);
    title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QLabel* subtitle = new QLabel("the Great Animal Project Editor", this);
    subtitle->setFont(robotoSubheader);
    subtitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    subtitle->setStyleSheet("color: #888;");
    titleLayout->addSpacing(20);

    // --------------------- COLUMNS LAYOUT
    QHBoxLayout* columnsLayout = new QHBoxLayout;
    QVBoxLayout* leftColumn = new QVBoxLayout;
    leftColumn->setSpacing(10);
    QVBoxLayout* rightColumn = new QVBoxLayout;
    rightColumn->setSpacing(10);

    QPushButton* newProject = new QPushButton("New Project", this);
    newProject->setFont(robotoButton);
    QPushButton* importFromDiskButton = new QPushButton("Open", this);
    importFromDiskButton->setFont(robotoButton);
    QPushButton* importFromZtdButton = new QPushButton("Import from ZTD", this);
    importFromZtdButton->setFont(robotoButton);
    QPushButton* exitApp = new QPushButton("Exit", this);
    exitApp->setFont(robotoButton);


    // ------------------------------- LEFT COLUMN

    titleLayout->addWidget(title);
    titleLayout->addWidget(subtitle);
    leftColumn->addLayout(titleLayout);
    leftColumn->addStretch();

    leftColumn->addWidget(newProject);
    leftColumn->addWidget(importFromDiskButton);
    leftColumn->addWidget(importFromZtdButton);
    leftColumn->addStretch();
    leftColumn->addWidget(exitApp);

    // ------------------------------- DIVIDER
    QFrame* divider = new QFrame(this);
    divider->setFrameShape(QFrame::VLine);
    divider->setFrameShadow(QFrame::Sunken);

    // -------------------------------- RIGHT COLUMN

    QLabel* recentWorkspaces = new QLabel("Recent Workspaces");
    recentWorkspaces->setFont(robotoSubheader);
    recentWorkspaces->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QPushButton* project1 = new QPushButton("Workspace 1", this);
    project1->setFont(robotoButton);
    QPushButton* project2 = new QPushButton("Workspace 2", this);
    project2->setFont(robotoButton);

    rightColumn->addWidget(recentWorkspaces);
    rightColumn->addWidget(project1);
    rightColumn->addWidget(project2);
    rightColumn->addStretch();

    // Install layouts
    welcomeLayout->addLayout(columnsLayout);

    columnsLayout->addLayout(leftColumn);
    columnsLayout->addWidget(divider);
    columnsLayout->addLayout(rightColumn);

    // forward signals
    connect(importFromDiskButton, &QPushButton::clicked, this, &GrWelcomeScreen::importProjectRequested);
    connect(importFromZtdButton, &QPushButton::clicked, this, &GrWelcomeScreen::importProjectFromZTDRequested);

}
