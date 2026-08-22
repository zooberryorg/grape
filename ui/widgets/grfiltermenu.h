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
signals:
    void filtersChanged();

private:
    QComboBox* filterDllFiles;
    QVBoxLayout* layout;
};

#endif // GRFILTERMENU_H
