#include "grwidget.h"

#include <QVBoxLayout>

GrWidget::GrWidget(QWidget *parent)
    : QWidget{parent}
{
    vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins( 2, 0, 2, 0 );
    vLayout->setSpacing(0);

}
