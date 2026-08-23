#include "gridselectorpopup.h"

#include "grlangtablebrowser.h"
#include <QVBoxLayout>
#include <QLabel>

#include "graltbutton.h"

GrIdSelectorPopup::GrIdSelectorPopup(QWidget *parent, const QVector<GrPE::Entry> &entries, const QStringList &dllNames)
    : QWidget{parent, Qt::Popup}
{
    setObjectName("explorerContainer");
    setAttribute(Qt::WA_StyledBackground, true);

    layout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout;
    QWidget* buttonArea = new QWidget(this);
    buttonArea->setLayout(buttonLayout);

    GrLangTableBrowser* browser = new GrLangTableBrowser(this, entries, dllNames);
    QLabel* label = new QLabel("ID Picker");
    GrAltButton* cancelButton = new GrAltButton("Cancel", this);
    GrAltButton* selectButton = new GrAltButton("Select", this);

    layout->addWidget(label);
    layout->addWidget(browser);
    layout->addWidget(buttonArea);

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(selectButton);
}

void GrIdSelectorPopup::handleSelected()
{
    emit cancelled();
    close();
}

void GrIdSelectorPopup::handleCancelled(GrLangTableBrowser *source)
{
    if (source->hasSelection()) {
        const GrPE::Entry entry = source->selectedEntry();
        emit idSelected(entry.id, entry.value);
    }
    close();
}
