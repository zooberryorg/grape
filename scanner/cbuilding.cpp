#include "cbuilding.h"


CBuilding::CBuilding(QString path)
    : CScenery(path)
{
    m_type = AssetType::Building;
    initMembers();
    initCharInts();
}


void CBuilding::initMembers () {
    m_members.clear();
    m_members.append("structures");
}

void CBuilding::initCharInts() {
    m_intchars[charInts]["cCapacity"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cToySatisfaction"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cTimeInside"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cDefaultCost"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cLowCost"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cMedCost"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cHighCost"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cPriceFactor"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cUpkeep"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cHideUser"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cSetLetterFacing"] = { "", Group::UI, Widget::Integer };
    m_intchars[charInts]["cDrawUser"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cHideCostChange"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cHideCommerceInfo"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cHideRegularInfo"] = { "", Group::Commerce, Widget::Float };
    m_intchars[charInts]["cHoldsOntoUser"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cUserTracker"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cIdler"] = "";
    m_intchars[charInts]["cExhibitViewer"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cAlternatePanelTitle"] = { "", Group::UI, Widget::Integer };
    m_intchars[charInts]["cDirectEntrance"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cHideBuilding"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cUserStaysOutside"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cUserTeleportsInside"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cUserUsesExit"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cUserUsesEntranceAsEmergencyExit"] = { "", Group::Slots, Widget::Integer };
    m_intchars[charInts]["cAdultChange"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cChildChange"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cHungerChange"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cThirstChange"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cBathroomChange"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cEnergyChange"] = { "", Group::Guests, Widget::Integer };
}
