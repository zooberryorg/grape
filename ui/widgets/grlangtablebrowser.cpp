#include "grlangtablebrowser.h"

#include <QVBoxLayout>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QHeaderView>

#include "grlangtablemodel.h"
#include "grpe.h"

GrLangTableBrowser::GrLangTableBrowser(QWidget *parent, const QString& path)
    : QWidget{parent}
{
    this->setObjectName("explorerContainer");
    this->setAttribute(Qt::WA_StyledBackground, true);

    QVBoxLayout* layout = new QVBoxLayout(this);
    GrLangTableModel* langModel = new GrLangTableModel(this);
    langModel->setEntries(GrPE::getStringTables(path));

    QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(langModel);

    QTableView* langTable = new QTableView(this);
    langTable->setModel(proxy);
    langTable->setSortingEnabled(true);
    langTable->horizontalHeader()->setStretchLastSection(true);

    layout->addWidget(langTable);
    layout->setContentsMargins(5, 5, 5, 5);
}
