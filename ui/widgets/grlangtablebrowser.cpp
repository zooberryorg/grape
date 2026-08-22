#include "grlangtablebrowser.h"

#include <QVBoxLayout>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QHeaderView>
#include <QTableView>

#include <QDir>
#include <QDirIterator>


#include "grlangtablemodel.h"
#include "grpe.h"
#include "grlineedit.h"

GrLangTableBrowser::GrLangTableBrowser(QWidget *parent, const QString& path)
    : QWidget{parent}
{
    this->setObjectName("explorerContainer");
    this->setAttribute(Qt::WA_StyledBackground, true);

    QVBoxLayout* layout = new QVBoxLayout(this);

    // searchbar setup
    GrLineEdit* searchbar = new GrLineEdit();
    searchbar->widget()->setPlaceholderText("Search");

    // table setup
    GrLangTableModel* langModel = new GrLangTableModel(this);
    loadLangFiles(path);
    langModel->setEntries(langFiles);
    QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(langModel);

    langTable = new QTableView(this);
    langTable->setModel(proxy);
    langTable->setSortingEnabled(true);
    langTable->horizontalHeader()->setStretchLastSection(true);

    // add to layout
    layout->addWidget(searchbar);
    layout->addWidget(langTable);
    layout->setContentsMargins(5, 5, 5, 5);
}

void GrLangTableBrowser::setupTableModel()
{
    GrLangTableModel* sourceModel = new GrLangTableModel(this);
    sourceModel->setEntries(langFiles);

    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(sourceModel);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(1);

    langTable->setModel(proxy);
}

void GrLangTableBrowser::loadLangFiles(const QString &path)
{
    for ( const auto& curPath : QDirListing(path) ) {
        QString folderName = curPath.fileName().toLower();

        bool isDll = curPath.fileName().toLower().contains(".dll");
        bool isLang = curPath.fileName().toLower().contains("lang");
        if ( curPath.isFile() && isDll && isLang ) {
            langFiles.append( GrPE::getStringTables(curPath.filePath()) );
        }
    }
}
