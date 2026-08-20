#include "grcheckbox.h"


#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>

GrCheckBox::GrCheckBox(QWidget *parent, const QString& label, const QString& caption)
    : QWidget{parent}
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins( 2, 0, 2, 0 );
    vLayout->setSpacing(0);
    checkbox = new QCheckBox(label);
    QLabel* captionLabel = new QLabel(caption);

    vLayout->addWidget(checkbox);
    vLayout->addWidget(captionLabel);
}
