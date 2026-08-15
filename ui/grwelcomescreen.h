#ifndef GRWELCOMESCREEN_H
#define GRWELCOMESCREEN_H

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QLabel;

class GrWelcomeScreen : public QWidget
{
public:
    GrWelcomeScreen();
private:
    QVBoxLayout* welcomeLayout;
    QVBoxLayout* workspaceVLLayout;

    QLabel* appTitleLabel;
    QLabel* appSubtitleLabel;
    QLabel* newProjectLabel;
};

#endif // GRWELCOMESCREEN_H
