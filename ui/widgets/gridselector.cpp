#include "gridselector.h"

#include "grlangtablebrowser.h"
#include <QVBoxLayout>
#include <QLabel>

#include "graltbutton.h"

GrIdSelector::GrIdSelector(QWidget *parent, GrLangTableBrowser* source = nullptr)
    : QWidget{parent}
{
    setObjectName("explorerContainer");
    setAttribute(Qt::WA_StyledBackground, true);

}
