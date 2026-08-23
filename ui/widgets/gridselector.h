#ifndef GRIDSELECTOR_H
#define GRIDSELECTOR_H

#include <QWidget>
#include "grlineedit.h"

class QVBoxLayout;
class QHBoxLayout;
class GrLangTableBrowser;

class GrIdSelector : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelector(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "", GrLangTableBrowser* source = nullptr);
    int selectedId() const { return m_selectedId; };
    QLineEdit* widget() { return m_lineEdit->widget(); };

private:
    int m_selectedId;
    GrLangTableBrowser* m_source;
    void openPicker();
    GrLineEdit* m_lineEdit;
    QVBoxLayout *vLayout;
    bool m_suppressNextFocus;
signals:
    void idChanged(int id);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void handleCancel();
    void handleIdSelected(int id, const QString &value, const QString& fileName);

};

#endif // GRIDSELECTOR_H
