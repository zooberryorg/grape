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
    Q_OBJECT
public:
    GrWelcomeScreen();
signals:
    void importProjectRequested();
    void importProjectFromZTDRequested();
};

#endif // GRWELCOMESCREEN_H
