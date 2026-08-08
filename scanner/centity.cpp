#include "centity.h"

CEntity::CEntity() {
    m_config["cr_part1"]["ncolors"] = "";

    QString charInts = "Characteristics/Integers";
    m_config[charInts]["cIconZoom"] = "";
    m_config[charInts]["cExpansionID"] = "";
    m_config[charInts]["cMoveable"] = "";
    m_config[charInts]["walkable"] = "";
    m_config[charInts]["walkableByTall"] = "";
    m_config[charInts]["cRubbleable"] = "";
    m_config[charInts]["cUseNumbersInName"] = "";
    m_config[charInts]["cUsesRealShadows"] = "";
    m_config[charInts]["cHasShadowImages"] = "";
    m_config[charInts]["cForceShadowBlack"] = "";
    m_config[charInts]["cDrawsLate"] = "";
    m_config[charInts]["cHeight"] = "";
    m_config[charInts]["cDepth"] = "";
    m_config[charInts]["cHasUnderwaterSection"] = "";
    m_config[charInts]["cIsTransient"] = "";
    m_config[charInts]["cUsesPlacementCube"] = "";
    m_config[charInts]["cShow"] = "";
    m_config[charInts]["cHitThreshold"] = "";
    m_config[charInts]["cAvoidEdges"] = "";
    m_config[charInts]["cFootprintX"] = "";
    m_config[charInts]["cFootprintY"] = "";
    m_config[charInts]["cFootprintZ"] = "";
    m_config[charInts]["cPlacementFootprintX"] = "";
    m_config[charInts]["cPlacementFootprintY"] = "";
    m_config[charInts]["cPlacementFootprintZ"] = "";
    m_config[charInts]["AvailableAtStartup"] = "";
}
