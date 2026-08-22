#include "gridselector.h"

#include "grlangtablebrowser.h"
#include <QVBoxLayout>
#include <QLabel>

#include "graltbutton.h"

GrIdSelector::GrIdSelector(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("explorerContainer");
    setAttribute(Qt::WA_StyledBackground, true);

    layout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout;
    QWidget* buttonArea = new QWidget(this);
    buttonArea->setLayout(buttonLayout);

    GrLangTableBrowser* browser = new GrLangTableBrowser;
    QLabel* label = new QLabel("ID Picker");
    GrAltButton* cancelButton = new GrAltButton("Cancel", this);
    GrAltButton* selectButton = new GrAltButton("Select", this);

    layout->addWidget(label);
    layout->addWidget(browser);
    layout->addWidget(buttonArea);

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(selectButton);
}
