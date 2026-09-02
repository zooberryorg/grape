#include "cbuilding.h"


CBuilding::CBuilding(QString path)
    : CScenery(path)
{
    m_type = AssetType::Building;
    initMembers();
    initCharInts();
    initCharFloats();
}

void CBuilding::initMembers () {
    m_members.clear();
    m_members.append("structures");
}

GrShared::Config CBuilding::allSections()
{
    return {
        &m_globals,
        &m_icon,
        &m_intchars,
        &m_floatchars,
        &m_animations,
    };
}


void CBuilding::initCharInts() {
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cCapacity", { "", Group::Slots, Widget::Integer } },
            { "cToySatisfaction", { "", Group::Needs, Widget::Integer } },
            { "cTimeInside", { "", Group::Slots, Widget::Integer } },
            { "cHideUser", { "", Group::Slots, Widget::Switch } },
            { "cSetLetterFacing", { "", Group::UI, Widget::Switch } },
            { "cDrawUser", { "", Group::Slots, Widget::Switch } },
            { "cHideCostChange", { "", Group::Commerce, Widget::Switch } },
            { "cHideCommerceInfo", { "", Group::Commerce, Widget::Switch } },
            { "cHideRegularInfo", { "", Group::Commerce, Widget::Switch } },
            { "cHoldsOntoUser", { "", Group::Slots, Widget::Switch } },
            { "cUserTracker", { "", Group::Slots, Widget::Switch } },
            { "cIdler", { "", Group::Traits, Widget::Switch } },
            { "cExhibitViewer", { "", Group::Exhibit, Widget::Switch } },
            { "cAlternatePanelTitle", { "", Group::UI, Widget::Switch } },
            { "cDirectEntrance", { "", Group::Slots, Widget::Switch } },
            { "cHideBuilding", { "", Group::Slots, Widget::Switch } },
            { "cUserStaysOutside", { "", Group::Slots, Widget::Switch } },
            { "cUserTeleportsInside", { "", Group::Slots, Widget::Switch } },
            { "cUserUsesExit", { "", Group::Slots, Widget::Switch } },
            { "cUserUsesEntranceAsEmergencyExit", { "", Group::Slots, Widget::Switch } },
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

void CBuilding::initCharFloats() {
    GrINI::SectionTemplate tmpl {
        "Characteristics/Floats",
        {
            { "cDefaultCost", { "", Group::Commerce, Widget::Float } },
            { "cLowCost", { "", Group::Commerce, Widget::Float } },
            { "cMedCost", { "", Group::Commerce, Widget::Float } },
            { "cHighCost", { "", Group::Commerce, Widget::Float } },
            { "cPriceFactor", { "", Group::Commerce, Widget::Float } },
            { "cUpkeep", { "", Group::Commerce, Widget::Float } }
        }
    };
}
