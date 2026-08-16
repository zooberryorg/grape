#include "cbuilding.h"


CBuilding::CBuilding(QString path)
    : CScenery(path)
{
    m_type = AssetType::Scenery;
    initMembers();
    initCharInts();
}


void CBuilding::initMembers () {
    m_members.clear();
    m_members.append("structures");
}

void CBuilding::initCharInts() {
    m_intchars[charInts]["cCapacity"] = "";
    m_intchars[charInts]["cToySatisfaction"] = "";
    m_intchars[charInts]["cTimeInside"] = "";
    m_intchars[charInts]["cDefaultCost"] = "";
    m_intchars[charInts]["cLowCost"] = "";
    m_intchars[charInts]["cMedCost"] = "";
    m_intchars[charInts]["cHighCost"] = "";
    m_intchars[charInts]["cPriceFactor"] = "";
    m_intchars[charInts]["cUpkeep"] = "";
    m_intchars[charInts]["cHideUser"] = "";
    m_intchars[charInts]["cSetLetterFacing"] = "";
    m_intchars[charInts]["cDrawUser"] = "";
    m_intchars[charInts]["cHideCostChange"] = "";
    m_intchars[charInts]["cHideCommerceInfo"] = "";
    m_intchars[charInts]["cHideRegularInfo"] = "";
    m_intchars[charInts]["cHoldsOntoUser"] = "";
    m_intchars[charInts]["cUserTracker"] = "";
    m_intchars[charInts]["cIdler"] = "";
    m_intchars[charInts]["cExhibitViewer"] = "";
    m_intchars[charInts]["cAlternatePanelTitle"] = "";
    m_intchars[charInts]["cDirectEntrance"] = "";
    m_intchars[charInts]["cHideBuilding"] = "";
    m_intchars[charInts]["cUserStaysOutside"] = "";
    m_intchars[charInts]["cUserTeleportsInside"] = "";
    m_intchars[charInts]["cUserUsesExit"] = "";
    m_intchars[charInts]["cUserUsesEntranceAsEmergencyExit"] = "";
    m_intchars[charInts]["cAdultChange"] = "";
    m_intchars[charInts]["cChildChange"] = "";
    m_intchars[charInts]["cHungerChange"] = "";
    m_intchars[charInts]["cThirstChange"] = "";
    m_intchars[charInts]["cBathroomChange"] = "";
    m_intchars[charInts]["cEnergyChange"] = "";
}
