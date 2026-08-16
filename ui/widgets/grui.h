#ifndef GRUI_H
#define GRUI_H

class QWidget;
class QString;
class QVariant;

namespace GrUI
{
    QWidget* createFieldWidget(const QString&, const QVariant&, QWidget*);
}

#endif // GRUI_H
