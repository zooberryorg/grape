#include "grlangtablebrowser.h"

#include <QVBoxLayout>
#include <QTableView>
#include <QSortFilterProxyModel>

#include "grlangtablemodel.h"
#include "grpe.h"

GrLangTableBrowser::GrLangTableBrowser(QWidget *parent, const QString& path)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    GrLangTableModel* langModel = new GrLangTableModel(this);
    langModel->setEntries(GrPE::getStringTables(path));

    QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(langModel);

    QTableView* langTable = new QTableView(this);
    langTable->setModel(proxy);
    langTable->setSortingEnabled(true);

    layout->addWidget(langTable);
}
