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
    filterDllFiles->addItems(dllFileNames);

    layout->addWidget(new QLabel("Search by File:", this));
    layout->addWidget(filterDllFiles);
}

