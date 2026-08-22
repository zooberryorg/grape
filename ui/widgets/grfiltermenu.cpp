#include "grfiltermenu.h"

#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QAbstractItemView>

#include "grgfx.h"

GrFilterMenu::GrFilterMenu(QWidget* parent, const QStringList& dllFileNames)
    : QWidget(parent, Qt::Popup)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("filterMenu");

    layout = new QVBoxLayout(this);

    filterDllFiles = new QComboBox(this);
    filterDllFiles->addItem("All Files");
    filterDllFiles->addItems(dllFileNames);
    filterDllFiles->setMaxVisibleItems(15);
    filterDllFiles->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    filterDllFiles->view()->setObjectName("filterMenuList");

    layout->addWidget(new QLabel("Search by File:", this));
    layout->addWidget(filterDllFiles);

    setGraphicsEffect(GrGfx::shadowFx());

    connect(filterDllFiles, &QComboBox::currentTextChanged, this, &GrFilterMenu::handleDllMenuChanged);
}

void GrFilterMenu::handleDllMenuChanged(const QString &selection)
{
    emit filtersChanged(selection == "All" ? QString() : selection);
}

