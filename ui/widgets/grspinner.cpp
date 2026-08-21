#include "grspinner.h"
#include "grgfx.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QSpinBox>

GrSpinner::GrSpinner(QWidget *parent, const QString& label, const QString& caption)
    : GrWidget{parent}
{
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->setSpacing(10);
    spinbox = new QSpinBox;
    QLabel* captionLabel = new QLabel(caption);
    QLabel* widgetLabel = new QLabel(label);

    QFont widgetFont = widgetLabel->font();
    widgetFont.setPointSize(8);
    widgetLabel->setFont(widgetFont);
    captionLabel->setFont(widgetFont);

    spinbox->setGraphicsEffect(GrGfx::shadowFx());
    widgetLabel->setGraphicsEffect(GrGfx::shadowFx());
    captionLabel->setGraphicsEffect(GrGfx::shadowFx());
    spinbox->setCursor(Qt::ArrowCursor);

    vLayout->addLayout(hLayout);
    hLayout->addWidget(widgetLabel);
    hLayout->addWidget(spinbox);
    if ( !caption.isEmpty() ) {
        vLayout->addWidget(captionLabel);
    }
}
