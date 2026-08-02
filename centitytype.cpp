#include "centitytype.h"

CEntityType::CEntityType() {
    mConfig["cr_part1"]["ncolors"] = "";

    QString charInts = "Characteristics/Integers";
    mConfig[charInts]["cIconZoom"] = "";
    mConfig[charInts]["cExpansionID"] = "";
    mConfig[charInts]["cMoveable"] = "";
    mConfig[charInts]["walkable"] = "";
    mConfig[charInts]["walkableByTall"] = "";
    mConfig[charInts]["cRubbleable"] = "";
    mConfig[charInts]["cUseNumbersInName"] = "";
    mConfig[charInts]["cUsesRealShadows"] = "";
    mConfig[charInts]["cHasShadowImages"] = "";
    mConfig[charInts]["cForceShadowBlack"] = "";
    mConfig[charInts]["cDrawsLate"] = "";
    mConfig[charInts]["cHeight"] = "";
    mConfig[charInts]["cDepth"] = "";
    mConfig[charInts]["cHasUnderwaterSection"] = "";
    mConfig[charInts]["cIsTransient"] = "";
    mConfig[charInts]["cUsesPlacementCube"] = "";
    mConfig[charInts]["cShow"] = "";
    mConfig[charInts]["cHitThreshold"] = "";
    mConfig[charInts]["cAvoidEdges"] = "";
    mConfig[charInts]["cFootprintX"] = "";
    mConfig[charInts]["cFootprintY"] = "";
    mConfig[charInts]["cFootprintZ"] = "";
    mConfig[charInts]["cPlacementFootprintX"] = "";
    mConfig[charInts]["cPlacementFootprintY"] = "";
    mConfig[charInts]["cPlacementFootprintZ"] = "";
    mConfig[charInts]["AvailableAtStartup"] = "";
}
