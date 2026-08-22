#include "graltbutton.h"

#include <QEvent>
#include <QEnterEvent>

#include "grgfx.h"

GrAltButton::GrAltButton(const QString& name, QWidget* parent)
    : QPushButton{name, parent}
{
    setObjectName("altButton");
    setAttribute(Qt::WA_Hover, true);

    setGraphicsEffect(GrGfx::shadowFx());
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

void GrAltButton::enterEvent(QEnterEvent *event)
{
    if ( !m_hoverIcon.isNull() ) {
        setIcon(m_hoverIcon);
    }
    QPushButton::enterEvent(event);
}

void GrAltButton::leaveEvent(QEvent *event)
{
    setIcon(m_normalIcon);
    QPushButton::leaveEvent(event);
}
