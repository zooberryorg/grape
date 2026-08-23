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

    m_source = new GrLangTableBrowser(this, entries, dllNames);
    QLabel* label = new QLabel("ID Picker");
    GrAltButton* cancelButton = new GrAltButton("Cancel", this);
    GrAltButton* selectButton = new GrAltButton("Select", this);

    layout->addWidget(label);
    layout->addWidget(m_source);
    layout->addWidget(buttonArea);

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(selectButton);

    connect(cancelButton, &QPushButton::clicked, this, &GrIdSelectorPopup::handleCancelled);
    connect(selectButton, &QPushButton::clicked, this, &GrIdSelectorPopup::handleSelected);
}

void GrIdSelectorPopup::handleSelected()
{
    if (m_source->hasSelection()) {
        const GrPE::Entry entry = m_source->selectedEntry();
        emit idSelected(entry.id, entry.value, entry.dllFileName);
    }
    close();
}

void GrIdSelectorPopup::handleCancelled()
{
    emit cancelled();
    close();
}
