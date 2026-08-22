#ifndef GRLANGTABLEBROWSER_H
#define GRLANGTABLEBROWSER_H

#include <QWidget>

class QSortFilterProxyModel;
class QTableView;

class GrLangTableBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit GrLangTableBrowser(QWidget *parent = nullptr, const QString& path = "");

    void setupTableModel();
signals:

private:
    QSortFilterProxyModel *proxy;
    QTableView *langTable;
};

#endif // GRLANGTABLEBROWSER_H
