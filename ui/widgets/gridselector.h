#ifndef GRIDSELECTOR_H
#define GRIDSELECTOR_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class GrLangTableBrowser;
class GrLineEdit;

class GrIdSelector : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelector(QWidget *parent = nullptr, GrLangTableBrowser* source = nullptr);
    int selectedId() const { return m_selectedId; };
private:
    int m_selectedId;
    GrLangTableBrowser* m_source;
    void openPicker();
    GrLineEdit* lineEdit;
signals:
    void idChanged(int id);
private slots:
    void handleCancel();
    void handleIdSelected();

};

#endif // GRIDSELECTOR_H
