#ifndef GRFILTERMENU_H
#define GRFILTERMENU_H

#include <QWidget>

class QComboBox;
class QVBoxLayout;
class GrLangFilterProxy;

class GrFilterMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GrFilterMenu(QWidget* parent = nullptr, const QStringList& dllFiles = {});

private slots:
    void handleDllMenuChanged(const QString& selection);
signals:
    void filtersChanged(const QString& selection);

private:
    QComboBox* filterDllFiles;
    QVBoxLayout* layout;
};

#endif // GRFILTERMENU_H
