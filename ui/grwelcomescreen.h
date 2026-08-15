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
private slots:
    void handleOpenProject();
};

#endif // GRWELCOMESCREEN_H
