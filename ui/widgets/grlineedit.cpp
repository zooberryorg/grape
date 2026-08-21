#include "grlineedit.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "grgfx.h"

GrLineEdit::GrLineEdit(QWidget *parent, const QString& caption, const QString& label)
    : GrWidget{parent}
{
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->setSpacing(10);
    lineEdit = new QLineEdit;
    QLabel* captionLabel = new QLabel(caption);
    QLabel* widgetLabel = new QLabel(label);

    QFont widgetFont = widgetLabel->font();
    widgetFont.setPointSize(8);
    widgetLabel->setFont(widgetFont);
    captionLabel->setFont(widgetFont);

    lineEdit->setGraphicsEffect(GrGfx::shadowFx());
    widgetLabel->setGraphicsEffect(GrGfx::shadowFx());
    captionLabel->setGraphicsEffect(GrGfx::shadowFx());
    lineEdit->setCursor(Qt::ArrowCursor);

    vLayout->addLayout(hLayout);
    hLayout->addWidget(widgetLabel);
    hLayout->addWidget(lineEdit);
    if ( !caption.isEmpty() ) {
        vLayout->addWidget(captionLabel);
    }
}
