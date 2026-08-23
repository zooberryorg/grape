#include "gridselector.h"

#include "grlangtablebrowser.h"
#include <QVBoxLayout>
#include <QLabel>

#include "graltbutton.h"
#include "grlineedit.h"

GrIdSelector::GrIdSelector(QWidget *parent, const QString& label, const QString& caption, GrLangTableBrowser* source)
    : QWidget{parent}
{
    setObjectName("explorerContainer");
    setAttribute(Qt::WA_StyledBackground, true);

    vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins( 0, 0, 0, 0 );

    lineEdit = new GrLineEdit(this, label, caption);
    lineEdit->widget()->installEventFilter(this);

    vLayout->addWidget(lineEdit);
}

void GrIdSelector::handleCancel(int id, const QString &value)
{
    m_selectedId = id;
    m_suppressNextFocus = true;
    lineEdit->widget()->setText(value);
    emit idChanged(id);
}

void GrIdSelector::handleIdSelected()
{
    m_suppressNextFocus = true;
}
