#include "canimal.h"

CAnimal::CAnimal(QString path)
    : CZTUnit(path)
{
    m_type = AssetType::Animal;
    initCharInts();
    initAnimPaths();
    initIcon();
    initMembers();
}

void CAnimal::load() {
    CSimpleIniA ini;
    int rc = ini.LoadFile(m_cpath.toStdString().c_str());
    if ( rc < 0 ) {
        // error handling here
    }

}

void CAnimal::initCharInts() {
    m_intchars[charInts]["cBoxFootprintX"] = "";
    m_intchars[charInts]["cBoxFootprintY"] = "";
    m_intchars[charInts]["cBoxFootprintZ"] = "";
    m_intchars[charInts]["cFamily"] = "";
    m_intchars[charInts]["cGenus"] = "";
    m_intchars[charInts]["cHabitat"] = "";
    m_intchars[charInts]["cLocation"] = "";
    m_intchars[charInts]["cEra"] = "";
    m_intchars[charInts]["cBreathThreshold"] = "";
    m_intchars[charInts]["cBreathIncrement"] = "";
    m_intchars[charInts]["cHungerThreshold"] = "";
    m_intchars[charInts]["cHungryHealthChange"] = "";
    m_intchars[charInts]["cHungerIncrement"] = "";
    m_intchars[charInts]["cFoodUnitValue"] = ""; // not in game files
    m_intchars[charInts]["cKeeperFoodUnitsEaten"] = "";
    m_intchars[charInts]["cNeededFood"] = "";
    m_intchars[charInts]["cNoFoodChange"] = "";
    m_intchars[charInts]["cInitialHappiness"] = "";
    m_intchars[charInts]["cMaxHits"] = "";
    m_intchars[charInts]["cPctHits"] = "";
    m_intchars[charInts]["cMaxEnergy"] = "";
    m_intchars[charInts]["cMaxDirty"] = ""; // not in game files
    m_intchars[charInts]["cMinDirty"] = ""; // not in game files
    m_intchars[charInts]["cSickChange"] = "";
    m_intchars[charInts]["cOtherAnimalSickChange"] = "";
    m_intchars[charInts]["cSickChance"] = "";
    m_intchars[charInts]["cSickRandomChance"] = ""; // not in game files
    m_intchars[charInts]["cCrowd"] = "";
    m_intchars[charInts]["cCrowdHappinessChange"] = "";
    m_intchars[charInts]["cZapHappinessChange"] = "";
    m_intchars[charInts]["cCaptivity"] = ""; // also cCaptivityCheck?
    m_intchars[charInts]["cReproductionChance"] = "";
    m_intchars[charInts]["cReproductionInterval"] = "";
    m_intchars[charInts]["cMatingType"] = "";
    m_intchars[charInts]["cOffspring"] = "";
    m_intchars[charInts]["cKeeperFrequency"] = "";
    m_intchars[charInts]["cNotEnoughKeepersChange"] = "";
    m_intchars[charInts]["cSocial"] = "";
    m_intchars[charInts]["cHabitatSize"] = ""; // also cSocialCheck?
    m_intchars[charInts]["cNumberAnimalsMin"] = "";
    m_intchars[charInts]["cNumberAnimalsMax"] = "";
    m_intchars[charInts]["cNumberMinChange"] = "";
    m_intchars[charInts]["cNumberMaxChange"] = "";
    m_intchars[charInts]["cHabitatPreference"] = "";
    m_intchars[charInts]["cBabyBornChange"] = "";
    m_intchars[charInts]["cEnergyIncrement"] = "";
    m_intchars[charInts]["cEnergyThreshold"] = "";
    m_intchars[charInts]["cDirtyIncrement"] = "";
    m_intchars[charInts]["cDirtyThreshold"] = "";
    m_intchars[charInts]["cSickTime"] = "";
    m_intchars[charInts]["cBabyToAdult"] = "";
    m_intchars[charInts]["cOtherFood"] = "";
    m_intchars[charInts]["cTreePref"] = "";
    m_intchars[charInts]["cRockPref"] = "";
    m_intchars[charInts]["cSpacePref"] = "";
    m_intchars[charInts]["cElevationPref"] = "";
    m_intchars[charInts]["cDepthMin"] = "";
    m_intchars[charInts]["cDepthMax"] = "";
    m_intchars[charInts]["cDepthChange"] = "";
    m_intchars[charInts]["cSalinityChange"] = "";
    m_intchars[charInts]["cSalinityHealthChange"] = "";
    m_intchars[charInts]["cHappyReproduceThreshold"] = "";
    m_intchars[charInts]["cBuildingUseChance"] = "";
    m_intchars[charInts]["cNoMateChange"] = "";
    m_intchars[charInts]["cTimeDeath"] = "";
    m_intchars[charInts]["cDeathChance"] = "";
    m_intchars[charInts]["cWaterNeeded"] = "";
    m_intchars[charInts]["cUnderwater"] = "";
    m_intchars[charInts]["cLandNeeded"] = "";
    m_intchars[charInts]["cEnterWaterChance"] = "";
    m_intchars[charInts]["cEnterTankChance"] = "";
    m_intchars[charInts]["cEnterLandChance"] = "";
    m_intchars[charInts]["cDrinkWaterChance"] = "";
    m_intchars[charInts]["cChaseAnimalChance"] = "";
    m_intchars[charInts]["cClimbsCliffs"] = "";
    m_intchars[charInts]["cBashStrength"] = "";
    m_intchars[charInts]["cAttractiveness"] = "";
    m_intchars[charInts]["cKeeperFoodType"] = "";
    m_intchars[charInts]["cIsClimber"] = "";
    m_intchars[charInts]["cIsJumper"] = "";
    m_intchars[charInts]["cSmallZoodoo"] = "";
    m_intchars[charInts]["cDinoZoodoo"] = "";
    m_intchars[charInts]["cGiantZoodoo"] = "";
    m_intchars[charInts]["cIsSpecialAnimal"] = "";
    m_intchars[charInts]["cNeedShelter"] = "";
    m_intchars[charInts]["cNeedToys"] = "";
    m_intchars[charInts]["cBabiesAttack"] = "";

    // cPrey support elsewhere
}

void CAnimal::initAnimPaths() {
    m_animpaths[animPaths]["f"] = "";
    m_animpaths[animPaths]["m"] = "";
    m_animpaths[animPaths]["y"] = "";
}

void CAnimal::initIcon() {
    m_icon["Icon"]["Icon"] = "";
}

void CAnimal::initMembers() {
    m_members.append("animals");
}

void CAnimal::initDefaultLcid() {
    m_defaultlcid[defaultLcid]["LCID"] = "";
}

void CAnimal::init1033() {
    m_1033[_1033]["cGeneralInfoFileName"] = "";
    m_1033[_1033]["cLongHelp"] = "";
    m_1033[_1033]["cName"] = "";
    m_1033[_1033]["cTheString"] = "";
}

