#include "grcheckbox.h"


#include <QHBoxLayout>

GrCheckbox::GrCheckbox(QWidget *parent, const QString& label)
    : QCheckBox{parent}
{
    QHBoxLayout* hLayout = new QHBoxLayout(this);

    checkbox = new QCheckBox();
}
