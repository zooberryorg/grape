#include "grspinner.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QSpinBox>

GrSpinner::GrSpinner(QWidget *parent, const QString& label, const QString& caption)
    : QWidget{parent}
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->setSpacing(10);
    vLayout->setContentsMargins( 2, 0, 2, 0 );
    vLayout->setSpacing(0);
    spinbox = new QSpinBox;
    QLabel* captionLabel = new QLabel(caption);
    QLabel* widgetLabel = new QLabel(label);

    QFont widgetFont = widgetLabel->font();
    widgetFont.setPointSize(8);
    widgetLabel->setFont(widgetFont);
    captionLabel->setFont(widgetFont);

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(4);
    shadowEffect->setColor(QColor(0, 0, 0, 140));
    shadowEffect->setOffset(0, 2);

    spinbox->setGraphicsEffect(shadowEffect);

    vLayout->addLayout(hLayout);
    hLayout->addWidget(widgetLabel);
    hLayout->addWidget(spinbox);
    if ( !caption.isEmpty() ) {
        vLayout->addWidget(captionLabel);
    }
}
