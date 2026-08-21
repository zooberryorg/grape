#include "grcheckbox.h"
#include "grgfx.h"

#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

GrCheckBox::GrCheckBox(QWidget *parent, const QString& label, const QString& caption)
    : GrWidget{parent}
{
    checkbox = new QCheckBox(label);
    QLabel* captionLabel = new QLabel(caption);

    checkbox->setGraphicsEffect(GrGfx::shadowFx());

    vLayout->addWidget(checkbox);
    vLayout->addWidget(captionLabel);
}
