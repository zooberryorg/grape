#include "gridselector.h"

#include "grlangtablebrowser.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>

#include "grlineedit.h"
#include "gridselectorpopup.h"

GrIdSelector::GrIdSelector(QWidget *parent, const QString& label, const QString& caption, GrLangTableBrowser* source)
    : QWidget{parent},
      m_source{source},
      m_selectedId{0},
      m_suppressNextFocus{false}
{
    setObjectName("explorerContainer");
    setAttribute(Qt::WA_StyledBackground, true);

    vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins( 0, 0, 0, 0 );

    m_lineEdit = new GrLineEdit(this, label, caption);
    m_lineEdit->widget()->installEventFilter(this);

    vLayout->addWidget(m_lineEdit);
}

void GrIdSelector::handleCancel()
{
    m_suppressNextFocus = true;
}

void GrIdSelector::handleIdSelected(int id, const QString &value)
{
    m_selectedId = id;
    m_suppressNextFocus = true;
    m_lineEdit->widget()->setText(value);
    emit idChanged(id);
}

bool GrIdSelector::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == m_lineEdit->widget() && event->type() == QEvent::FocusIn) {
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
    if ( !m_source ) {
        qWarning() << "GrIdSelector: no source browser set, cannot open picker.";
        return;
    }

    GrIdSelectorPopup* popup = new GrIdSelectorPopup(this, m_source->entries(), m_source->dllNames());

    const QPoint pos = m_lineEdit->mapToGlobal(QPoint(0, m_lineEdit->height() + 2));
    popup->move(pos);
    popup->show();

    connect(popup, &GrIdSelectorPopup::idSelected, this, &GrIdSelector::handleIdSelected);
    connect(popup, &GrIdSelectorPopup::cancelled, this, &GrIdSelector::handleCancel);
}
