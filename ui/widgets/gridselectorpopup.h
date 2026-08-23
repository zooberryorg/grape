#ifndef GRIDSELECTORPOPUP_H
#define GRIDSELECTORPOPUP_H

#include <QWidget>
#include "grpe.h"

class QVBoxLayout;
class QHBoxLayout;
class GrLangTableBrowser;

class GrIdSelectorPopup : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelectorPopup(QWidget *parent = nullptr, const QVector<GrPE::Entry> &entries = {}, const QStringList &dllNames = {});
private:
    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
    int m_selectedId;
    GrLangTableBrowser* m_source;
    void openPicker();
signals:
    void idSelected(int id, const QString& value);
    void cancelled();
};

#endif // GRIDSELECTORPOPUP_H
