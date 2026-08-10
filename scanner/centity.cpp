#include "centity.h"

CEntity::CEntity(QString path)
    : GrAsset(path)
{
    m_intchars["cr_part1"]["ncolors"] = "";

    QString charInts = "Characteristics/Integers";
    m_intchars[charInts]["cIconZoom"] = "";
    m_intchars[charInts]["cExpansionID"] = "";
    m_intchars[charInts]["cMoveable"] = "";
    m_intchars[charInts]["walkable"] = "";
    m_intchars[charInts]["walkableByTall"] = "";
    m_intchars[charInts]["cRubbleable"] = "";
    m_intchars[charInts]["cUseNumbersInName"] = "";
    m_intchars[charInts]["cUsesRealShadows"] = "";
    m_intchars[charInts]["cHasShadowImages"] = "";
    m_intchars[charInts]["cForceShadowBlack"] = "";
    m_intchars[charInts]["cDrawsLate"] = "";
    m_intchars[charInts]["cHeight"] = "";
    m_intchars[charInts]["cDepth"] = "";
    m_intchars[charInts]["cHasUnderwaterSection"] = "";
    m_intchars[charInts]["cIsTransient"] = "";
    m_intchars[charInts]["cUsesPlacementCube"] = "";
    m_intchars[charInts]["cShow"] = "";
    m_intchars[charInts]["cHitThreshold"] = "";
    m_intchars[charInts]["cAvoidEdges"] = "";
    m_intchars[charInts]["cFootprintX"] = "";
    m_intchars[charInts]["cFootprintY"] = "";
    m_intchars[charInts]["cFootprintZ"] = "";
    m_intchars[charInts]["cPlacementFootprintX"] = "";
    m_intchars[charInts]["cPlacementFootprintY"] = "";
    m_intchars[charInts]["cPlacementFootprintZ"] = "";
    m_intchars[charInts]["AvailableAtStartup"] = "";
}
