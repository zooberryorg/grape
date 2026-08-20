#include "grcheckbox.h"


#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

GrCheckBox::GrCheckBox(QWidget *parent, const QString& label, const QString& caption)
    : QWidget{parent}
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins( 2, 0, 2, 0 );
    vLayout->setSpacing(0);
    checkbox = new QCheckBox(label);
    QLabel* captionLabel = new QLabel(caption);

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(4);
    shadowEffect->setColor(QColor(0, 0, 0, 120));
    shadowEffect->setOffset(0, 1);

    checkbox->setGraphicsEffect(shadowEffect);

    vLayout->addWidget(checkbox);
    vLayout->addWidget(captionLabel);
}
