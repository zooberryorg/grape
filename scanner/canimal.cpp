#include "canimal.h"

CAnimal::CAnimal(QString path)
    : CZTUnit(path)
{
    m_type = AssetType::Animal;
    initProjectName();
    initCharInts();
    initAnimPaths();
    initIcon();
    initMembers();
    initDefaultLcid();
    init1033();
}

void CAnimal::load() {
    CSimpleIniA ini;
    int rc = ini.LoadFile(m_cpath.toStdString().c_str());
    if ( rc < 0 ) {
        // error handling here
    }

    GrINI::loadConfig( ini,
        {
            &m_intchars,
            &m_animpaths,
            &m_icon,
            &m_defaultlcid,
            &m_1033
        }
    );
}

void CAnimal::save() {

}

void CAnimal::initCharInts() {
    m_intchars[charInts]["cBoxFootprintX"] = { "", Group::ID, Widget::Integer };
    m_intchars[charInts]["cBoxFootprintY"] = { "", Group::ID, Widget::Integer };
    m_intchars[charInts]["cBoxFootprintZ"] = { "", Group::ID, Widget::Integer };
    m_intchars[charInts]["cFamily"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cGenus"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cHabitat"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cLocation"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cEra"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cBreathThreshold"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cBreathIncrement"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cHungerThreshold"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cHungryHealthChange"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cHungerIncrement"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cFoodUnitValue"] = { "", Group::Needs, Widget::Integer }; // not in game files
    m_intchars[charInts]["cKeeperFoodUnitsEaten"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cNeededFood"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cNoFoodChange"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cInitialHappiness"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cMaxHits"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cPctHits"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cMaxEnergy"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cMaxDirty"] = { "", Group::Needs, Widget::Integer }; // not in game files
    m_intchars[charInts]["cMinDirty"] = { "", Group::Needs, Widget::Integer }; // not in game files
    m_intchars[charInts]["cSickChange"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cOtherAnimalSickChange"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cSickChance"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cSickRandomChance"] = { "", Group::Needs, Widget::Integer }; // not in game files
    m_intchars[charInts]["cCrowd"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cCrowdHappinessChange"] = { "", Group::Guests, Widget::Integer };
    m_intchars[charInts]["cZapHappinessChange"] = { "", Group::Keepers, Widget::Integer };
    m_intchars[charInts]["cCaptivity"] = { "", Group::Keepers, Widget::Integer }; // also cCaptivityCheck?
    m_intchars[charInts]["cReproductionChance"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cReproductionInterval"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cMatingType"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cOffspring"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cKeeperFrequency"] = { "", Group::Keepers, Widget::Integer };
    m_intchars[charInts]["cNotEnoughKeepersChange"] = { "", Group::Keepers, Widget::Integer };
    m_intchars[charInts]["cSocial"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cHabitatSize"] = { "", Group::Exhibit, Widget::Integer }; // also cSocialCheck?
    m_intchars[charInts]["cNumberAnimalsMin"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cNumberAnimalsMax"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cNumberMinChange"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cNumberMaxChange"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cHabitatPreference"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cBabyBornChange"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cEnergyIncrement"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cEnergyThreshold"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cDirtyIncrement"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cDirtyThreshold"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cSickTime"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cBabyToAdult"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cOtherFood"] = { "", Group::Needs, Widget::Integer };
    m_intchars[charInts]["cTreePref"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cRockPref"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cSpacePref"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cElevationPref"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cDepthMin"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cDepthMax"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cDepthChange"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cSalinityChange"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cSalinityHealthChange"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cHappyReproduceThreshold"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cBuildingUseChance"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cNoMateChange"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cTimeDeath"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cDeathChance"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cWaterNeeded"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cUnderwater"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cLandNeeded"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cEnterWaterChance"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cEnterTankChance"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cEnterLandChance"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cDrinkWaterChance"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cChaseAnimalChance"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cClimbsCliffs"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cBashStrength"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cAttractiveness"] = { "", Group::Social, Widget::Integer };
    m_intchars[charInts]["cKeeperFoodType"] = { "", Group::Keepers, Widget::Integer };
    m_intchars[charInts]["cIsClimber"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cIsJumper"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cSmallZoodoo"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cDinoZoodoo"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cGiantZoodoo"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cIsSpecialAnimal"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cNeedShelter"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cNeedToys"] = { "", Group::Exhibit, Widget::Integer };
    m_intchars[charInts]["cBabiesAttack"] = { "", Group::Social, Widget::Integer };

    // cPrey support elsewhere
}

void CAnimal::initAnimPaths() {
    m_animpaths[animPaths]["f"] = { "", Group::ID, Widget::Integer };
    m_animpaths[animPaths]["m"] = { "", Group::ID, Widget::Integer };
    m_animpaths[animPaths]["y"] = { "", Group::ID, Widget::Integer };
}

void CAnimal::initIcon() {
    m_icon["Icon"]["Icon"] = { "", Group::ID, Widget::Integer };
}

void CAnimal::initMembers() {
    m_members.append("animals");
}

void CAnimal::initDefaultLcid() {
    m_defaultlcid[defaultLcid]["LCID"] = { "", Group::ID, Widget::Integer };
}

void CAnimal::init1033() {
    m_1033[_1033]["cGeneralInfoFileName"] = { "", Group::ID, Widget::LineText };
    m_1033[_1033]["cLongHelp"] = { "", Group::ID, Widget::LineText };
    m_1033[_1033]["cName"] = { "", Group::ID, Widget::LineText };
    m_1033[_1033]["cTheString"] = { "", Group::ID, Widget::LineText };
}

