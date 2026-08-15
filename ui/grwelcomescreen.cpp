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

    welcomeLayout->addLayout(titleLayout);
    welcomeLayout->addLayout(columnsLayout);

    columnsLayout->addLayout(leftColumn);
    columnsLayout->addLayout(rightColumn);

    titleLayout->addWidget(title);
    titleLayout->addWidget(subtitle);

    leftColumn->addWidget(newProject);
    leftColumn->addWidget(openProject);
    leftColumn->addWidget(importProject);
    leftColumn->addWidget(exitApp);
}
