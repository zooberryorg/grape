#ifndef GRSLOTS_H
#define GRSLOTS_H

class QWidget;
class QStackedWidget;
class GrWorkspace;
class QMenuBar;

class GrSlots
{
public:
    GrSlots();
    static void handleProjectOpen(QWidget*, QStackedWidget*, GrWorkspace*, QMenuBar*);
};

#endif // GRSLOTS_H
