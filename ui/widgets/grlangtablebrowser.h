#ifndef GRLANGTABLEBROWSER_H
#define GRLANGTABLEBROWSER_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include "grpe.h"

class QSortFilterProxyModel;
class QTableView;
class GrLineEdit;

class GrLangTableBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit GrLangTableBrowser(QWidget *parent = nullptr, const QString& path = "");

    void setupTableModel();
    void loadLangFiles(const QString& path);
signals:

private:
    QSortFilterProxyModel *proxy;
    QTableView *langTable;
    QVector<GrPE::Entry> langFiles;
    GrLineEdit *searchbar;
private slots:
    void handleClearSearch();
};

#endif // GRLANGTABLEBROWSER_H
