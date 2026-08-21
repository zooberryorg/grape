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

    QGraphicsDropShadowEffect *sSpinbox = new QGraphicsDropShadowEffect(this);
    sSpinbox->setBlurRadius(4);
    sSpinbox->setColor(QColor(0, 0, 0, 140));
    sSpinbox->setOffset(0, 2);

    QGraphicsDropShadowEffect *sWidgetLabel = new QGraphicsDropShadowEffect(this);
    sWidgetLabel->setBlurRadius(4);
    sWidgetLabel->setColor(QColor(0, 0, 0, 140));
    sWidgetLabel->setOffset(0, 2);

    QGraphicsDropShadowEffect *sCaptionLabel = new QGraphicsDropShadowEffect(this);
    sCaptionLabel->setBlurRadius(4);
    sCaptionLabel->setColor(QColor(0, 0, 0, 140));
    sCaptionLabel->setOffset(0, 2);


    spinbox->setGraphicsEffect(sSpinbox);
    widgetLabel->setGraphicsEffect(sWidgetLabel);
    captionLabel->setGraphicsEffect(sCaptionLabel);
    spinbox->setCursor(Qt::ArrowCursor);

    vLayout->addLayout(hLayout);
    hLayout->addWidget(widgetLabel);
    hLayout->addWidget(spinbox);
    if ( !caption.isEmpty() ) {
        vLayout->addWidget(captionLabel);
    }
}
