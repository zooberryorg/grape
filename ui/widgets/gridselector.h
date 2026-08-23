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
    explicit GrIdSelector(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "", GrLangTableBrowser* source = nullptr);
    int selectedId() const { return m_selectedId; };
private:
    int m_selectedId;
    GrLangTableBrowser* m_source;
    void openPicker();
    GrLineEdit* lineEdit;
    QVBoxLayout *vLayout;
    bool m_suppressNextFocus;
signals:
    void idChanged(int id);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void handleCancel();
    void handleIdSelected(int id, const QString &value);

};

#endif // GRIDSELECTOR_H
