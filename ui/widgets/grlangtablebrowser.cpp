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
#include "grlangfilterproxy.h"
#include "graltbutton.h"

GrLangTableBrowser::GrLangTableBrowser(QWidget *parent, const QString& path)
    : QWidget{parent}
{
    this->setObjectName("explorerContainer");
    this->setAttribute(Qt::WA_StyledBackground, true);

    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* searchLayout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QWidget* searchArea = new QWidget;

    // searchbar setup
    GrLineEdit* searchbar = new GrLineEdit();
    searchbar->widget()->setPlaceholderText("Search");

    // action buttons
    GrAltButton* clearText = new GrAltButton;
    searchArea->setLayout(searchLayout);
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(clearText);

    // table setup
    GrLangTableModel* langModel = new GrLangTableModel(this);
    loadLangFiles(path);
    langModel->setEntries(langFiles);

    // proxy filter model
    GrLangFilterProxy* proxy = new GrLangFilterProxy(this);
    proxy->setSourceModel(langModel);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // setup table view
    langTable = new QTableView(this);
    langTable->setModel(proxy);
    langTable->setSortingEnabled(true);
    langTable->horizontalHeader()->setStretchLastSection(true);

    // add to layout
    layout->addWidget(searchArea);
    layout->addWidget(langTable);
    layout->setContentsMargins(5, 5, 5, 5);

    connect(searchbar->widget(), &QLineEdit::textChanged, proxy, &QSortFilterProxyModel::setFilterFixedString);
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
