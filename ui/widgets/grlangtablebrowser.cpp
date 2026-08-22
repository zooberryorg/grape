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
#include "grgfx.h"
#include "grfiltermenu.h"

GrLangTableBrowser::GrLangTableBrowser(QWidget *parent, const QString& path)
    : QWidget{parent}
{
    this->setObjectName("explorerContainer");
    this->setAttribute(Qt::WA_StyledBackground, true);

    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* searchLayout = new QHBoxLayout(this);
    searchLayout->setContentsMargins(0, 0, 0, 0);

    QWidget* searchArea = new QWidget;

    // searchbar setup
    searchbar = new GrLineEdit();
    searchbar->widget()->setPlaceholderText("Search");

    // action buttons
    GrAltButton* clearText = new GrAltButton;
    filterButton = new GrAltButton;
    int iconSize = 18;
    clearText->setNormalIcon(GrGfx::setSvgColor(":/icons/text-clear.svg", "#fff", iconSize, iconSize));
    clearText->setHoverIcon((GrGfx::setSvgColor(":/icons/text-clear.svg", "#c9a961", iconSize, iconSize)));
    clearText->setFixedSize(QSize(20,20));
    clearText->setToolTip("Clear search");

    filterButton->setNormalIcon(GrGfx::setSvgColor(":/icons/adjustments.svg", "#fff", iconSize, iconSize));
    filterButton->setHoverIcon((GrGfx::setSvgColor(":/icons/adjustments.svg", "#c9a961", iconSize, iconSize)));
    filterButton->setFixedSize(QSize(20,20));
    filterButton->setToolTip("Filter results");

    searchArea->setLayout(searchLayout);
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(clearText);
    searchLayout->addWidget(filter);

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
    connect(clearText, &QPushButton::clicked, this, &GrLangTableBrowser::handleClearSearch);
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
        dllFileNames.append(curPath.fileName());

        bool isDll = curPath.fileName().toLower().contains(".dll");
        bool isLang = curPath.fileName().toLower().contains("lang");
        if ( curPath.isFile() && isDll && isLang ) {
            langFiles.append( GrPE::getStringTables(curPath.filePath()) );
        }
    }
}

void GrLangTableBrowser::showFilterMenu()
{
    GrFilterMenu* menu = new GrFilterMenu(this, dllFileNames);
    menu->setAttribute(Qt::WA_DeleteOnClose);

    const QPoint pos = filterButton->mapToGlobal(QPoint(0, filterButton->height() + 2));
    menu->move(pos);
    menu->show();

    connect(menu, &GrFilterMenu::filtersChanged, this, &GrLangTableBrowser::updateFilterProxy);
}

void GrLangTableBrowser::handleClearSearch() {
    searchbar->widget()->clear();
}
