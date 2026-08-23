#ifndef GRIDSELECTORPOPUP_H
#define GRIDSELECTORPOPUP_H

#include <QWidget>
#include "grpe.h"

class QVBoxLayout;
class QHBoxLayout;
class GrLangTableBrowser;
class GrAltButton;

class GrIdSelectorPopup : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelectorPopup(QWidget *parent = nullptr, const QVector<GrPE::Entry> &entries = {}, const QStringList &dllNames = {});
private:
    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
    GrLangTableBrowser* m_source;
    GrAltButton* cancelButton;
    GrAltButton* selectButton;
signals:
    void idSelected(int id, const QString& value);
    void cancelled();
private slots:
    void handleSelected();
    void handleCancelled();
};

#endif // GRIDSELECTORPOPUP_H
