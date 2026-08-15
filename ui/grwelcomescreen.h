#ifndef GRWELCOMESCREEN_H
#define GRWELCOMESCREEN_H

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QStackedWidget;
class GrWorkspace;
class QMenuBar;

class GrWelcomeScreen : public QWidget
{
public:
    GrWelcomeScreen(QWidget*, QStackedWidget*, GrWorkspace*, QMenuBar*);
private:
    QWidget* mainWindow;
    QStackedWidget* stackedLayouts;
    GrWorkspace* workspace;
    QMenuBar* menuBar;
private slots:
    void handleOpenProject();
};

#endif // GRWELCOMESCREEN_H
