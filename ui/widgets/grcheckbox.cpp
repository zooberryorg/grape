#include "grcheckbox.h"


#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

GrCheckBox::GrCheckBox(QWidget *parent, const QString& label, const QString& caption)
    : GrWidget{parent}
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins( 2, 0, 2, 0 );
    vLayout->setSpacing(0);
    checkbox = new QCheckBox(label);
    QLabel* captionLabel = new QLabel(caption);

    checkbox->setGraphicsEffect(shadowEffect);

    vLayout->addWidget(checkbox);
    vLayout->addWidget(captionLabel);
}
