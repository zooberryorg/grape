#ifndef GRPROJECT_H
#define GRPROJECT_H

#include <QWidget>

class GrAsset;
class QFrame;
class GrPropertyPanelMgr;

class GrProject : public QWidget
{
    Q_OBJECT
public:
    explicit GrProject(QWidget *parent = nullptr);
    void showAsset(GrAsset* asset);

signals:
private:
    QFrame* canvasArea;
    GrPropertyPanelMgr* panelMgr;

};

#endif // GRPROJECT_H
