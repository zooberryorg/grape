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
    QHBoxLayout* workspaceHLayout;
    QVBoxLayout* workspaceVLLayout;

    QLabel* newProjectLabel;
};

#endif // GRWELCOMESCREEN_H
