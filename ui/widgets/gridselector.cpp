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
      m_suppressNextFocus{false},
      m_popup{nullptr}
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

void GrIdSelector::handleIdSelected(int id, const QString &value, const QString& fileName)
{
    m_selectedId = id;
    m_suppressNextFocus = true;
    m_lineEdit->widget()->setText(QString::number(id));
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

    if ( m_popup ) {
        return;
    }

    m_popup = new GrIdSelectorPopup(this, m_source->entries(), m_source->dllNames());
    m_popup->setAttribute(Qt::WA_DeleteOnClose);

    const QPoint pos = m_lineEdit->mapToGlobal(QPoint(0, m_lineEdit->height() + 2));
    m_popup->move(pos);
    m_popup->show();

    connect(m_popup, &GrIdSelectorPopup::idSelected, this, &GrIdSelector::handleIdSelected);
    connect(m_popup, &GrIdSelectorPopup::cancelled, this, &GrIdSelector::handleCancel);
    // when popup destroyed
    connect(m_popup, &QObject::destroyed, this, [this] {
            m_popup = nullptr;
        });
}
