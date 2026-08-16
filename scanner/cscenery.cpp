#include "cscenery.h"
#include "grini.h"

CScenery::CScenery(QString path)
    : CEntity(path)
{
    m_type = AssetType::Scenery;
    initProjectName();
    initGlobals();
    initIcon();
    initMembers();
    initCharInts();
    initDefaultLcid();
    init1033();
}

void CScenery::load()
{
    CSimpleIniA ini;
    int rc = ini.LoadFile(m_cpath.toStdString().c_str());
    if ( rc < 0 ) {
        // error handling here
    }

    QHash<QString, QString> foundCharInts = GrINI::getKeyValuesInSection(ini, charInts);
    GrINI::assignNewValuesToKeys(m_intchars, foundCharInts);

    QHash<QString, QString> foundAnimations = GrINI::getKeyValuesInSection(ini, animations);
    GrINI::assignNewValuesToKeys(m_animpaths, foundAnimations);

    QHash<QString, QString> foundIcons = GrINI::getKeyValuesInSection(ini, icons);
    for ( const QString& value : foundIcons ) {
        if ( value.contains("SE") ) {
            m_icon[icons]["IconSE"] = value;
        }
        else if ( value.contains("SW") ) {
            m_icon[icons]["IconSW"] = value;
        }
        else if ( value.contains("NE") ) {
            m_icon[icons]["IconNE"] = value;
        }
        else if ( value.contains("NW") ) {
            m_icon[icons]["IconNW"] = value;
        }
    }

    QHash<QString, QString> foundGlobals = GrINI::getKeyValuesInSection(ini, globals);
    GrINI::assignNewValuesToKeys(m_globals, foundGlobals);

    QHash<QString, QString> foundDefaultLcid = GrINI::getKeyValuesInSection(ini, defaultLcid);
    GrINI::assignNewValuesToKeys(m_defaultlcid, foundDefaultLcid);

    QHash<QString, QString> found1033 = GrINI::getKeyValuesInSection(ini, _1033);
    GrINI::assignNewValuesToKeys(m_1033, found1033);
}

void CScenery::save()
{

}

void CScenery::initGlobals()
{
    m_globals[globals]["Type"] = "";
}

void CScenery::initIcon()
{
    m_icon[icons]["IconSE"] = "";
    m_icon[icons]["IconSW"] = "";
    m_icon[icons]["IconNW"] = "";
    m_icon[icons]["IconNE"] = "";

}

void CScenery::initMembers()
{
    m_members.append("scenery");
}

void CScenery::initCharInts()
{
    m_intchars[charInts]["cPurchaseCost"] = "";
    m_intchars[charInts]["cHelpId"] = "";
    m_intchars[charInts]["cNameId"] = "";
    m_intchars[charInts]["cHabitat"] = "";
    m_intchars[charInts]["cLocation"] = "";
    m_intchars[charInts]["cEra"] = "";
    m_intchars[charInts]["cMaxFoodUnits"] = "";
    m_intchars[charInts]["cStink"] = "";
    m_intchars[charInts]["cEstheticWeight"] = "";
    m_intchars[charInts]["cSelectable"] = "";
    m_intchars[charInts]["cDeletable"] = "";
    m_intchars[charInts]["cFoliage"] = "";
    m_intchars[charInts]["cAutoRotate"] = "";
    m_intchars[charInts]["cLand"] = "";
    m_intchars[charInts]["cSwims"] = ""; // not in game files
    m_intchars[charInts]["cUnderwater"] = "";
    m_intchars[charInts]["cSurface"] = "";
    m_intchars[charInts]["cSubmerge"] = "";
    m_intchars[charInts]["cOnlySwims"] = "";
    m_intchars[charInts]["cNeedsConfirm"] = "";
    m_intchars[charInts]["cGawkOnlyFromFront"] = "";
    m_intchars[charInts]["cDeadOnLand"] = "";
    m_intchars[charInts]["cDeadOnFlatWater"] = ""; // not in game files
    m_intchars[charInts]["cDeadUnderwater"] = ""; // not in game files
    m_intchars[charInts]["cUsesTreeRubble"] = "";
    m_intchars[charInts]["cForcesSceneryRubble"] = "";
    m_intchars[charInts]["cBlocksLos"] = "";
}

void CScenery::initDefaultLcid()
{
    m_defaultlcid[defaultLcid]["LCID"] = "";
}

void CScenery::init1033()
{
    m_1033[_1033]["cGeneralInfoFileName"] = "";
    m_1033[_1033]["cLongHelp"] = "";
    m_1033[_1033]["cName"] = "";
    m_1033[_1033]["cTheString"] = "";
}

void CScenery::initAnimations()
{
    m_animations[animations]["idle"] = "";
    m_animations[animations]["IDLE"] = "";
    m_animations[animations]["used"] = "";
    m_animations[animations]["USED"] = "";

}
