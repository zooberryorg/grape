#ifndef GRWORKSPACE_H
#define GRWORKSPACE_H

#include <QWidget>
#include <QFrame>

class QHBoxLayout;
class QSplitter;
class GrProjectTree;
class GrCanvas;
class GrAsset;
class QStackedWidget;
class GrProject;

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

private slots:
    void handleAssetSelected(GrAsset*);

};

#endif // GRWORKSPACE_H
