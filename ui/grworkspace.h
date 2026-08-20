#ifndef GRWORKSPACE_H
#define GRWORKSPACE_H

#include <QWidget>
#include <QFrame>

class QHBoxLayout;
class QVBoxLayout;
class QSplitter;
class GrProjectTree;
class GrCanvas;
class GrAsset;
class QStackedWidget;
class GrProject;
class QStatusBar;

class GrWorkspace : public QWidget
{
    Q_OBJECT
public:
    explicit GrWorkspace(QWidget *parent = nullptr);
    void addProject(QString dir);

private:
    // projects
    std::vector<std::unique_ptr<GrAsset>> projects;

    // UI stuff
    QHBoxLayout* workspaceHLayout; // horizontal layout (central parent)
    QSplitter* hSplitter; // workspace splitter (workspaceHLayout parent)

    // workspace (left)
    GrProjectTree* projectTree;

    // workspace (right)
    QStackedWidget* projectStack;
    QHash<QString, GrProject*> m_projects;

    QVBoxLayout* workspaceVLayout;
    QSplitter *vSplitter;
    QStatusBar* statusBar;
private slots:
    void handleAssetSelected(GrAsset* asset);

};

#endif // GRWORKSPACE_H
