#ifndef GRLANGTABLEBROWSER_H
#define GRLANGTABLEBROWSER_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include "grpe.h"

class QSortFilterProxyModel;
class QTableView;
class GrLineEdit;
class GrAltButton;
class GrLangTableModel;
class GrLangFilterProxy;
class QHBoxLayout;
class QVBoxLayout;

class GrLangTableBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit GrLangTableBrowser(QWidget *parent = nullptr, const QString& path = "");
    explicit GrLangTableBrowser(QWidget *parent, const QVector<GrPE::Entry>& entries, const QStringList& dllNames);

    void showFilterMenu();
    QVector<GrPE::Entry> entries() const { return langFiles; }
    QStringList dllNames() const { return dllFileNames; }
signals:

private:
    GrLangFilterProxy *proxy;
    QTableView *langTable;
    QVector<GrPE::Entry> langFiles;
    QStringList dllFileNames;
    GrLineEdit *searchbar;
    GrAltButton *filterButton;
    GrLangTableModel *langModel;
    void initFilterProxy();

    QHBoxLayout* searchLayout;
    QVBoxLayout* layout;

    void initLangBrowser();
    void setupTableModel();
    void loadLangFiles();

    QWidget *searchArea;
    GrAltButton *clearTextButton;
    QString m_path;
private slots:
    void handleClearSearch();
};

#endif // GRLANGTABLEBROWSER_H
