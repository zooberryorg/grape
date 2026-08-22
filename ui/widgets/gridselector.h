#ifndef GRIDSELECTOR_H
#define GRIDSELECTOR_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class GrLangTableBrowser;

class GrIdSelector : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelector(QWidget *parent = nullptr, GrLangTableBrowser* source = nullptr);
    int selectedId() const { return m_selectedId; };
private:
    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
    int m_selectedId;
    GrLangTableBrowser* m_source;
signals:
    void idChanged(int id);

};

#endif // GRIDSELECTOR_H
