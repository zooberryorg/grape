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
    m_path = path;
    initLangBrowser();
}

GrLangTableBrowser::GrLangTableBrowser(QWidget *parent, const QVector<GrPE::Entry> &entries, const QStringList &dllNames)
{
    langFiles = entries;
    dllFileNames = dllNames;
    initLangBrowser();
}

void GrLangTableBrowser::initLangBrowser() {
    setObjectName("explorerContainer");
    setAttribute(Qt::WA_StyledBackground, true);

    layout = new QVBoxLayout(this);
    searchLayout = new QHBoxLayout;
    searchLayout->setContentsMargins(0, 0, 0, 0);

    searchArea = new QWidget;

    // searchbar setup
    searchbar = new GrLineEdit();
    searchbar->widget()->setPlaceholderText("Search");

    // action buttons
    clearTextButton = new GrAltButton;
    filterButton = new GrAltButton;
    int iconSize = 18;
    int btnSize = 25;
    clearTextButton->setNormalIcon(GrGfx::setSvgColor(":/icons/text-clear.svg", "#fff", iconSize, iconSize));
    clearTextButton->setHoverIcon((GrGfx::setSvgColor(":/icons/text-clear.svg", "#c9a961", iconSize, iconSize)));
    clearTextButton->setFixedSize(QSize(btnSize,btnSize));
    clearTextButton->setToolTip("Clear search");

    filterButton->setNormalIcon(GrGfx::setSvgColor(":/icons/adjustments.svg", "#fff", iconSize, iconSize));
    filterButton->setHoverIcon((GrGfx::setSvgColor(":/icons/adjustments.svg", "#c9a961", iconSize, iconSize)));
    filterButton->setFixedSize(QSize(btnSize,btnSize));
    filterButton->setToolTip("Filter results");

    searchArea->setLayout(searchLayout);
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(clearTextButton);
    searchLayout->addWidget(filterButton);

    // table setup
    langModel = new GrLangTableModel(this);
    if ( langFiles.isEmpty() ) {
        loadLangFiles();
    }
    langModel->setEntries(langFiles);

    // setup table view
    langTable = new QTableView(this);
    langTable->setSortingEnabled(true);
    langTable->horizontalHeader()->setStretchLastSection(true);
    langTable->verticalHeader()->setVisible(false);
    langTable->setShowGrid(false);
    langTable->setAlternatingRowColors(true);
    langTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    langTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // setup proxy
    initFilterProxy();

    // add to layout
    layout->addWidget(searchArea);
    layout->addWidget(langTable);
    layout->setContentsMargins(5, 5, 5, 5);

    connect(searchbar->widget(), &QLineEdit::textChanged, proxy, &QSortFilterProxyModel::setFilterFixedString);
    connect(clearTextButton, &QPushButton::clicked, this, &GrLangTableBrowser::handleClearSearch);
    connect(filterButton, &QPushButton::clicked, this, &GrLangTableBrowser::showFilterMenu);
}

void GrLangTableBrowser::setupTableModel()
{
    GrLangTableModel* sourceModel = new GrLangTableModel(this);
    sourceModel->setEntries(langFiles);

    proxy = new GrLangFilterProxy(this);
    proxy->setSourceModel(sourceModel);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(1);

    langTable->setModel(proxy);
}

void GrLangTableBrowser::loadLangFiles()
{
    for ( const auto& curPath : QDirListing(m_path) ) {
        QString folderName = curPath.fileName().toLower();

        bool isDll = curPath.fileName().toLower().contains(".dll");
        bool isLang = curPath.fileName().toLower().contains("lang");
        if ( curPath.isFile() && isDll && isLang ) {
            langFiles.append( GrPE::getStringTables(curPath.filePath()) );
            dllFileNames.append(curPath.fileName());
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

    connect(menu, &GrFilterMenu::filtersChanged, proxy, &GrLangFilterProxy::setDllFilter);
}

void GrLangTableBrowser::initFilterProxy()
{
    proxy = new GrLangFilterProxy(this);
    proxy->setSourceModel(langModel);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    langTable->setModel(proxy);
}

void GrLangTableBrowser::handleClearSearch() {
    searchbar->widget()->clear();
}
