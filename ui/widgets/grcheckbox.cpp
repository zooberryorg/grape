#include "grcheckbox.h"


#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>

GrCheckbox::GrCheckbox(QWidget *parent, const QString& label, const QString& caption)
    : QWidget{parent}
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QCheckBox* checkbox = new QCheckBox(label);
    QLabel* captionLabel = new QLabel(caption);

    vLayout->addWidget(checkbox);
    vLayout->addWidget(captionLabel);
}
