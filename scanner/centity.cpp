#include "centity.h"

CEntity::CEntity(QString path)
    : GrAsset(path)
{
    m_intchars[charInts]["cIconZoom"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cExpansionID"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cMoveable"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["walkable"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["walkableByTall"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cRubbleable"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cUseNumbersInName"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cUsesRealShadows"] = { "", Group::Graphics, Widget::Switch };
    m_intchars[charInts]["cHasShadowImages"] = { "", Group::Graphics, Widget::Switch };
    m_intchars[charInts]["cForceShadowBlack"] = { "", Group::Graphics, Widget::Switch };
    m_intchars[charInts]["cDrawsLate"] = { "", Group::Graphics, Widget::Switch };
    m_intchars[charInts]["cHeight"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cDepth"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cHasUnderwaterSection"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cIsTransient"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cUsesPlacementCube"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cShow"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cHitThreshold"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cAvoidEdges"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cFootprintX"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cFootprintY"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cFootprintZ"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cPlacementFootprintX"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cPlacementFootprintY"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cPlacementFootprintZ"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["AvailableAtStartup"] = { "", Group::UI, Widget::Switch };
}
