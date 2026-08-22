#include "graltbutton.h"


GrAltButton::GrAltButton(const QString& name, QWidget* parent)
    : QPushButton{name, parent}
{
    setObjectName("altButton");
    setAttribute(Qt::WA_Hover, true);
    installEventFilter(this);
}

void GrAltButton::setNormalIcon(const QIcon &icon)
{
    m_normalIcon = icon;
    setIcon(m_normalIcon);
}

void GrAltButton::setHoverIcon(const QIcon &icon)
{
    m_hoverIcon = icon;
}
