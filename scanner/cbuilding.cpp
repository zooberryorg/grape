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

GrShared::Config CBuilding::allSections()
{
    return {
        &m_icon,
        &m_intchars,
        &m_floatchars,

        &m_globals,
        &m_animpaths,
        &m_suitableobjects,
        &m_behaviorsets,
        &m_ambientanims,
        &m_defaultlcid,
        &m_1033,
        &m_animations,
        &m_filtersounds
    };
}


void CBuilding::initCharInts() {
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cCapacity", { "", Group::Slots, Widget::Integer } },
            { "cToySatisfaction", { "", Group::Needs, Widget::Integer } },
            { "cTimeInside", { "", Group::Slots, Widget::Integer } },
            { "cDefaultCost", { "", Group::Commerce, Widget::Float } },
            { "cLowCost", { "", Group::Commerce, Widget::Float } },
            { "cMedCost", { "", Group::Commerce, Widget::Float } },
            { "cHighCost", { "", Group::Commerce, Widget::Float } },
            { "cPriceFactor", { "", Group::Commerce, Widget::Float } },
            { "cUpkeep", { "", Group::Commerce, Widget::Float } },
            { "cHideUser", { "", Group::Slots, Widget::Integer } },
            { "cSetLetterFacing", { "", Group::UI, Widget::Integer } },
            { "cDrawUser", { "", Group::Slots, Widget::Integer } },
            { "cHideCostChange", { "", Group::Commerce, Widget::Float } },
            { "cHideCommerceInfo", { "", Group::Commerce, Widget::Float } },
            { "cHideRegularInfo", { "", Group::Commerce, Widget::Float } },
            { "cHoldsOntoUser", { "", Group::Slots, Widget::Integer } },
            { "cUserTracker", { "", Group::Slots, Widget::Integer } },
            { "cIdler", { "", Group::Traits, Widget::Integer } },
            { "cExhibitViewer", { "", Group::Exhibit, Widget::Integer } },
            { "cAlternatePanelTitle", { "", Group::UI, Widget::Integer } },
            { "cDirectEntrance", { "", Group::Slots, Widget::Integer } },
            { "cHideBuilding", { "", Group::Slots, Widget::Integer } },
            { "cUserStaysOutside", { "", Group::Slots, Widget::Integer } },
            { "cUserTeleportsInside", { "", Group::Slots, Widget::Integer } },
            { "cUserUsesExit", { "", Group::Slots, Widget::Integer } },
            { "cUserUsesEntranceAsEmergencyExit", { "", Group::Slots, Widget::Integer } },
            { "cAdultChange", { "", Group::Guests, Widget::Integer } },
            { "cChildChange", { "", Group::Guests, Widget::Integer } },
            { "cHungerChange", { "", Group::Guests, Widget::Integer } },
            { "cThirstChange", { "", Group::Guests, Widget::Integer } },
            { "cBathroomChange", { "", Group::Guests, Widget::Integer } },
            { "cEnergyChange", { "", Group::Guests, Widget::Integer } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}
