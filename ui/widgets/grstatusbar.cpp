#include "grstatusbar.h"

#include <QLabel>
#include <QFont>

GrStatusBar::GrStatusBar(QWidget *parent)
{
    version = new QLabel("GrAPE 0.1.0", this);
    QFont versionFont = version->font();
    versionFont.setPointSize(10);
    version->setFont(versionFont);
    addPermanentWidget(version);
}
