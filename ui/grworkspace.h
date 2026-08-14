#ifndef GRWORKSPACE_H
#define GRWORKSPACE_H

#include <QWidget>
#include <QFrame>

class QHBoxLayout;
class QSplitter;
class GrProjectTree;
class GrCanvas;

class GrWorkspace : public QWidget
{
    Q_OBJECT
public:
    explicit GrWorkspace(QWidget *parent = nullptr);

private:
    QHBoxLayout* workspaceHLayout; // horizontal layout (central parent)
    QSplitter* hSplitter; // workspace splitter (workspaceHLayout parent)

    // workspace (left)
    QWidget* projectTree;

    // workspace (center)
    QFrame* canvasArea;

signals:

};

#endif // GRWORKSPACE_H
