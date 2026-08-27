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

    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cBoxFootprintX", { "", Group::ID, Widget::Integer } },
            { "cBoxFootprintY", { "", Group::ID, Widget::Integer } },
            { "cBoxFootprintZ", { "", Group::ID, Widget::Integer } },
            { "cFamily", { "", Group::ID, Widget::IdPicker } },
            { "cGenus", { "", Group::ID, Widget::IdPicker } },
            { "cHabitat", { "", Group::ID, Widget::IdPicker } },
            { "cLocation", { "", Group::ID, Widget::IdPicker } },
            { "cEra", { "", Group::ID, Widget::IdPicker } },
            { "cBreathThreshold", { "", Group::Traits, Widget::Integer } },
            { "cBreathIncrement", { "", Group::Traits, Widget::Integer } },
            { "cHungerThreshold", { "", Group::Needs, Widget::Integer } },
            { "cHungryHealthChange", { "", Group::Needs, Widget::Integer } },
            { "cHungerIncrement", { "", Group::Needs, Widget::Integer } },
            { "cFoodUnitValue", { "", Group::Needs, Widget::Integer } }, // not in game files
            { "cKeeperFoodUnitsEaten", { "", Group::Needs, Widget::Integer } },
            { "cNeededFood", { "", Group::Needs, Widget::Integer } },
            { "cNoFoodChange", { "", Group::Needs, Widget::Integer } },
            { "cInitialHappiness", { "", Group::Needs, Widget::Integer } },
            { "cMaxHits", { "", Group::Traits, Widget::Integer }  },
            { "cPctHits", { "", Group::Traits, Widget::Integer }  },
            { "cMaxEnergy", { "", Group::Needs, Widget::Integer }  },
            { "cMaxDirty", { "", Group::Needs, Widget::Integer }  }, // not in game files
            { "cMinDirty", { "", Group::Needs, Widget::Integer }  }, // not in game files
            { "cSickChange", { "", Group::Needs, Widget::Integer }  },
            { "cOtherAnimalSickChange", { "", Group::Needs, Widget::Integer }  },
            { "cSickChance", { "", Group::Needs, Widget::Integer }  },
            { "cSickRandomChance", { "", Group::Needs, Widget::Integer }  }, // not in game files
            { "cCrowd", { "", Group::Guests, Widget::Integer }  },
            { "cCrowdHappinessChange", { "", Group::Guests, Widget::Integer }  },
            { "cZapHappinessChange", { "", Group::Keepers, Widget::Integer }  },
            { "cCaptivity", { "", Group::Keepers, Widget::Integer }  }, // also cCaptivityCheck?
            { "cReproductionChance", { "", Group::Social, Widget::Integer } },
            { "cReproductionInterval", { "", Group::Social, Widget::Integer } },
            { "cMatingType", { "", Group::Social, Widget::Integer } },
            { "cOffspring", { "", Group::Social, Widget::Integer } },
            { "cKeeperFrequency", { "", Group::Keepers, Widget::Integer } },
            { "cNotEnoughKeepersChange", { "", Group::Keepers, Widget::Integer } },
            { "cSocial", { "", Group::Social, Widget::Integer } },
            { "cHabitatSize", { "", Group::Exhibit, Widget::Integer } }, // also cSocialCheck?
            { "cNumberAnimalsMin", { "", Group::Exhibit, Widget::Integer } },
            { "cNumberAnimalsMax", { "", Group::Exhibit, Widget::Integer } },
            { "cNumberMinChange", { "", Group::Exhibit, Widget::Integer } },
            { "cNumberMaxChange", { "", Group::Exhibit, Widget::Integer } },
            { "cHabitatPreference", { "", Group::Exhibit, Widget::Integer } },
            { "cBabyBornChange", { "", Group::Social, Widget::Integer } },
            { "cEnergyIncrement", { "", Group::Needs, Widget::Integer } },
            { "cEnergyThreshold", { "", Group::Needs, Widget::Integer } },
            { "cDirtyIncrement", { "", Group::Needs, Widget::Integer } },
            { "cDirtyThreshold", { "", Group::Needs, Widget::Integer } },
            { "cSickTime", { "", Group::Needs, Widget::Integer } },
            { "cBabyToAdult", { "", Group::Social, Widget::Integer } },
            { "cOtherFood", { "", Group::Needs, Widget::Integer } },
            { "cTreePref", { "", Group::Exhibit, Widget::Integer } },
            { "cRockPref", { "", Group::Exhibit, Widget::Integer } },
            { "cSpacePref", { "", Group::Exhibit, Widget::Integer } },
            { "cElevationPref", { "", Group::Exhibit, Widget::Integer } },
            { "cDepthMin", { "", Group::Exhibit, Widget::Integer } },
            { "cDepthMax", { "", Group::Exhibit, Widget::Integer } },
            { "cDepthChange", { "", Group::Exhibit, Widget::Integer } },
            { "cSalinityChange", { "", Group::Exhibit, Widget::Integer } },
            { "cSalinityHealthChange", { "", Group::Exhibit, Widget::Integer } },
            { "cHappyReproduceThreshold", { "", Group::Social, Widget::Integer } },
            { "cBuildingUseChance", { "", Group::Exhibit, Widget::Integer } },
            { "cNoMateChange", { "", Group::Social, Widget::Integer } },
            { "cTimeDeath", { "", Group::Traits, Widget::Integer } },
            { "cDeathChance", { "", Group::Traits, Widget::Integer } },
            { "cWaterNeeded", { "", Group::Exhibit, Widget::Integer } },
            { "cUnderwater", { "", Group::Exhibit, Widget::Integer } },
            { "cLandNeeded", { "", Group::Exhibit, Widget::Integer } },
            { "cEnterWaterChance", { "", Group::Exhibit, Widget::Integer } },
            { "cEnterTankChance", { "", Group::Exhibit, Widget::Integer } },
            { "cEnterLandChance", { "", Group::Exhibit, Widget::Integer } },
            { "cDrinkWaterChance", { "", Group::Exhibit, Widget::Integer } },
            { "cChaseAnimalChance", { "", Group::Social, Widget::Integer } },
            { "cClimbsCliffs", { "", Group::Traits, Widget::Integer } },
            { "cBashStrength", { "", Group::Traits, Widget::Integer } },
            { "cAttractiveness", { "", Group::Social, Widget::Integer } },
            { "cKeeperFoodType", { "", Group::Keepers, Widget::Integer } },
            { "cIsClimber", { "", Group::Traits, Widget::Integer } },
            { "cIsJumper", { "", Group::Traits, Widget::Integer } },
            { "cSmallZoodoo", { "", Group::Traits, Widget::Integer } },
            { "cDinoZoodoo", { "", Group::Traits, Widget::Integer } },
            { "cGiantZoodoo", { "", Group::Traits, Widget::Integer } },
            { "cIsSpecialAnimal", { "", Group::Traits, Widget::Integer } },
            { "cNeedShelter", { "", Group::Exhibit, Widget::Integer } },
            { "cNeedToys", { "", Group::Exhibit, Widget::Integer } },
            { "cBabiesAttack", { "", Group::Social, Widget::Integer } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());

    // cPrey support elsewhere
}

void CAnimal::initAnimPaths() {
    GrINI::SectionTemplate tmpl {
        "AnimPaths ",
        {
            { "f", { "", Group::ID, Widget::Integer } },
            { "m", { "", Group::ID, Widget::Integer } },
            { "y", { "", Group::ID, Widget::Integer } }
        }
    };
}

void CAnimal::initIcon() {
    GrINI::SectionTemplate tmpl {
        "Icon",
        {
            { "Icon", { "", Group::ID, Widget::Integer } }
        }
    };

    GrINI::registerSubtypes(m_icon, tmpl, subtypes());
}

void CAnimal::initMembers() {
    m_members.append("animals");
}

void CAnimal::initDefaultLcid() {
    GrINI::SectionTemplate tmpl {
        "LCID",
        {
            { "LCID", { "", Group::ID, Widget::Integer } }
        }
    };
    GrINI::registerSubtypes(m_defaultlcid, tmpl, subtypes());
}

void CAnimal::init1033() {
    GrINI::SectionTemplate tmpl {
        "1033",
        {
            { "cGeneralInfoFileName", { "", Group::ID, Widget::LineText } },
            { "cLongHelp", { "", Group::ID, Widget::LineText } },
            { "cName", { "", Group::ID, Widget::LineText } },
            { "cTheString", { "", Group::ID, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_1033, tmpl, subtypes());
}

GrShared::SubtypeList CAnimal::subtypes() const
{
    return {
        {"m", "Male"},
        {"f", "Female"},
        {"y", "Young"}
    };
}

