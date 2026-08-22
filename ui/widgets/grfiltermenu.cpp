#include "grfiltermenu.h"

#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>

GrFilterMenu::GrFilterMenu(QWidget* parent, const QStringList& dllFileNames)
    : QWidget(parent, Qt::Popup)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("filterMenu");

    layout = new QVBoxLayout(this);

    filterDllFiles = new QComboBox(this);
    filterDllFiles->addItem("All Files");
    filterDllFiles->addItems(dllFileNames);

    layout->addWidget(new QLabel("Search by File:", this));
    layout->addWidget(filterDllFiles);

    connect(filterDllFiles, &QComboBox::currentTextChanged, this, &GrFilterMenu::handleDllMenuChanged);
}

void GrFilterMenu::handleDllMenuChanged(const QString &selection)
{
    emit filtersChanged(selection == "All" ? QString() : selection);
}

