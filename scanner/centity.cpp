#include "centity.h"

CEntity::CEntity(QString path)
    : GrAsset(path)
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cIconZoom", { "", Group::UI, Widget::Switch } },
            { "cExpansionID", { "", Group::UI, Widget::Switch } },
            { "cMoveable", { "", Group::UI, Widget::Switch } },
            { "walkable", { "", Group::Traits, Widget::Switch } },
            { "walkableByTall", { "", Group::Traits, Widget::Switch } },
            { "cRubbleable", { "", Group::Traits, Widget::Switch } },
            { "cUseNumbersInName", { "", Group::UI, Widget::Switch } },
            { "cUsesRealShadows", { "", Group::Graphics, Widget::Switch } },
            { "cHasShadowImages", { "", Group::Graphics, Widget::Switch } },
            { "cForceShadowBlack", { "", Group::Graphics, Widget::Switch } },
            { "cDrawsLate", { "", Group::Graphics, Widget::Switch } },
            { "cHeight", { "", Group::Traits, Widget::Switch } },
            { "cDepth", { "", Group::Traits, Widget::Switch } },
            { "cHasUnderwaterSection", { "", Group::Traits, Widget::Switch } },
            { "cIsTransient", { "", Group::Traits, Widget::Switch } },
            { "cUsesPlacementCube", { "", Group::UI, Widget::Switch } },
            { "cShow", { "", Group::UI, Widget::Switch } },
            { "cHitThreshold", { "", Group::Traits, Widget::Switch } },
            { "cAvoidEdges", { "", Group::UI, Widget::Switch } },
            { "cFootprintX", { "", Group::UI, Widget::Switch } },
            { "cFootprintY", { "", Group::UI, Widget::Switch } },
            { "cFootprintZ", { "", Group::UI, Widget::Switch } },
            { "cPlacementFootprintX", { "", Group::UI, Widget::Switch } },
            { "cPlacementFootprintY", { "", Group::UI, Widget::Switch } },
            { "cPlacementFootprintZ", { "", Group::UI, Widget::Switch } },
            { "AvailableAtStartup", { "", Group::UI, Widget::Switch } }
        }
    };

    GrINI::registeSubtypes(m_intchars, tmpl, subtypes());
}
