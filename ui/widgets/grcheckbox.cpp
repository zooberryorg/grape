#include "grcheckbox.h"
#include "grgfx.h"

#include <QHBoxLayout>
#include <QCheckBox>
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

    checkbox->setGraphicsEffect(GrGfx::shadowFx());

    vLayout->addWidget(checkbox);
    vLayout->addWidget(captionLabel);
}
