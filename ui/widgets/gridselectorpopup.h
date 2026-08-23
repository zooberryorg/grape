#ifndef GRIDSELECTORPOPUP_H
#define GRIDSELECTORPOPUP_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class GrLangTableBrowser;

class GrIdSelectorPopup : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelectorPopup(QWidget *parent = nullptr);
private:
    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
    int m_selectedId;
    GrLangTableBrowser* m_source;
    void openPicker();
signals:

};

#endif // GRIDSELECTORPOPUP_H
