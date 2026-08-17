#ifndef GRUI_H
#define GRUI_H

class QWidget;
class QString;
class QVariant;

namespace GrUI
{
    enum WidgetType {
        TerrainBuilder,
        PreyBuilder,
        AssetPicker,
        LineText,
        MultilineText,
        Switch,
        IdPicker,
        Integer,
        Float
    };

    QWidget* createFieldWidget(const QString&, const QVariant&, QWidget*);
}

#endif // GRUI_H
