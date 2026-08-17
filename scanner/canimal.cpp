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

    QHash<QString, QString> foundCharInts = GrINI::getKeyValuesInSection(ini, charInts);
    GrINI::assignNewValuesToKeys(m_intchars, foundCharInts);

    QHash<QString, QString> foundAnimPaths = GrINI::getKeyValuesInSection(ini, animPaths);
    GrINI::assignNewValuesToKeys(m_animpaths, foundAnimPaths);

    QHash<QString, QString> foundIcons = GrINI::getKeyValuesInSection(ini, "Icon");
    GrINI::assignNewValuesToKeys(m_icon, foundIcons);

    QHash<QString, QString> foundDefaultLcid = GrINI::getKeyValuesInSection(ini, defaultLcid);
    GrINI::assignNewValuesToKeys(m_defaultlcid, foundDefaultLcid);

    QHash<QString, QString> found1033 = GrINI::getKeyValuesInSection(ini, _1033);
    GrINI::assignNewValuesToKeys(m_1033, found1033);
}

void CAnimal::save() {

}

void CAnimal::initCharInts() {
    m_intchars[charInts]["cBoxFootprintX"] = { "", Group::ID, GrWidget::Integer };
    m_intchars[charInts]["cBoxFootprintY"] = { "", Group::ID, GrWidget::Integer };
    m_intchars[charInts]["cBoxFootprintZ"] = { "", Group::ID, GrWidget::Integer };
    m_intchars[charInts]["cFamily"] = { "", Group::ID, GrWidget::IdPicker };
    m_intchars[charInts]["cGenus"] = { "", Group::ID, GrWidget::IdPicker };
    m_intchars[charInts]["cHabitat"] = { "", Group::ID, GrWidget::IdPicker };
    m_intchars[charInts]["cLocation"] = { "", Group::ID, GrWidget::IdPicker };
    m_intchars[charInts]["cEra"] = { "", Group::ID, GrWidget::IdPicker };
    m_intchars[charInts]["cBreathThreshold"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cBreathIncrement"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cHungerThreshold"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cHungryHealthChange"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cHungerIncrement"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cFoodUnitValue"] = { "", Group::NeedsSatisfaction, GrWidget::Integer }; // not in game files
    m_intchars[charInts]["cKeeperFoodUnitsEaten"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNeededFood"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNoFoodChange"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cInitialHappiness"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cMaxHits"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cPctHits"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cMaxEnergy"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cMaxDirty"] = { "", Group::NeedsSatisfaction, GrWidget::Integer }; // not in game files
    m_intchars[charInts]["cMinDirty"] = { "", Group::NeedsSatisfaction, GrWidget::Integer }; // not in game files
    m_intchars[charInts]["cSickChange"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cOtherAnimalSickChange"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSickChance"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSickRandomChance"] = { "", Group::NeedsSatisfaction, GrWidget::Integer }; // not in game files
    m_intchars[charInts]["cCrowd"] = { "", Group::GuestSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cCrowdHappinessChange"] = { "", Group::GuestSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cZapHappinessChange"] = { "", Group::KeeperSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cCaptivity"] = { "", Group::KeeperSatisfaction, GrWidget::Integer }; // also cCaptivityCheck?
    m_intchars[charInts]["cReproductionChance"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cReproductionInterval"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cMatingType"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cOffspring"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cKeeperFrequency"] = { "", Group::KeeperSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNotEnoughKeepersChange"] = { "", Group::KeeperSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSocial"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cHabitatSize"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer }; // also cSocialCheck?
    m_intchars[charInts]["cNumberAnimalsMin"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNumberAnimalsMax"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNumberMinChange"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNumberMaxChange"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cHabitatPreference"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cBabyBornChange"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cEnergyIncrement"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cEnergyThreshold"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cDirtyIncrement"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cDirtyThreshold"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSickTime"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cBabyToAdult"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cOtherFood"] = { "", Group::NeedsSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cTreePref"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cRockPref"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSpacePref"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cElevationPref"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cDepthMin"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cDepthMax"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cDepthChange"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSalinityChange"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cSalinityHealthChange"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cHappyReproduceThreshold"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cBuildingUseChance"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNoMateChange"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cTimeDeath"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cDeathChance"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cWaterNeeded"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cUnderwater"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cLandNeeded"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cEnterWaterChance"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cEnterTankChance"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cEnterLandChance"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cDrinkWaterChance"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cChaseAnimalChance"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cClimbsCliffs"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cBashStrength"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cAttractiveness"] = { "", Group::Social, GrWidget::Integer };
    m_intchars[charInts]["cKeeperFoodType"] = { "", Group::KeeperSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cIsClimber"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cIsJumper"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cSmallZoodoo"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cDinoZoodoo"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cGiantZoodoo"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cIsSpecialAnimal"] = { "", Group::Traits, GrWidget::Integer };
    m_intchars[charInts]["cNeedShelter"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cNeedToys"] = { "", Group::ExhibitSatisfaction, GrWidget::Integer };
    m_intchars[charInts]["cBabiesAttack"] = { "", Group::Social, GrWidget::Integer };

    // cPrey support elsewhere
}

void CAnimal::initAnimPaths() {
    m_animpaths[animPaths]["f"] = { "", Group::ID, GrWidget::Integer };
    m_animpaths[animPaths]["m"] = { "", Group::ID, GrWidget::Integer };
    m_animpaths[animPaths]["y"] = { "", Group::ID, GrWidget::Integer };
}

void CAnimal::initIcon() {
    m_icon["Icon"]["Icon"] = { "", Group::ID, GrWidget::Integer };
}

void CAnimal::initMembers() {
    m_members.append("animals");
}

void CAnimal::initDefaultLcid() {
    m_defaultlcid[defaultLcid]["LCID"] = { "", Group::ID, GrWidget::Integer };
}

void CAnimal::init1033() {
    m_1033[_1033]["cGeneralInfoFileName"] = { "", Group::ID, GrWidget::LineText };
    m_1033[_1033]["cLongHelp"] = { "", Group::ID, GrWidget::LineText };
    m_1033[_1033]["cName"] = { "", Group::ID, GrWidget::LineText };
    m_1033[_1033]["cTheString"] = { "", Group::ID, GrWidget::LineText };
}

