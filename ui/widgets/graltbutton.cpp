#include "graltbutton.h"


GrAltButton::GrAltButton(const QString& name, QWidget* parent)
    : QPushButton{name, parent}
{
    setObjectName("altButton");
    setAttribute(Qt::WA_Hover, true);
    installEventFilter(this);
}
