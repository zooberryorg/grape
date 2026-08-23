#include "gridselector.h"

#include "grlangtablebrowser.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>

#include "graltbutton.h"
#include "grlineedit.h"
#include "gridselectorpopup.h"

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

void GrIdSelector::handleCancel()
{
    m_suppressNextFocus = true;
}

void GrIdSelector::handleIdSelected(int id, const QString &value)
{
    m_selectedId = id;
    m_suppressNextFocus = true;
    lineEdit->widget()->setText(value);
    emit idChanged(id);
}

bool GrIdSelector::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == lineEdit->widget() && event->type() == QEvent::FocusIn) {
        if (m_suppressNextFocus) {
            m_suppressNextFocus = false;
        } else {
            openPicker();
        }
    }
    return QWidget::eventFilter(watched, event);
}

void GrIdSelector::openPicker()
{
    GrIdSelectorPopup* popup = new GrIdSelectorPopup(this, m_source->entries(), m_source->dllNames());

    const QPoint pos = lineEdit->mapToGlobal(QPoint(0, lineEdit->height() + 2));
    popup->move(pos);
    popup->show();

    connect(popup, &GrIdSelectorPopup::idSelected, this, &GrIdSelector::handleIdSelected);
    connect(popup, &GrIdSelectorPopup::cancelled, this, &GrIdSelector::handleCancel);
}
