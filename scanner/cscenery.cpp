#include "cscenery.h"


CScenery::CScenery(QString path)
    : CEntity(path)
{
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

}

void CScenery::save()
{

}

void CScenery::initGlobals()
{

}

void CScenery::initIcon()
{

}

void CScenery::initMembers()
{

}

void CScenery::initCharInts()
{
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

}

void CScenery::init1033()
{

}

void CScenery::initAnimations()
{
    m_animpaths[animations]["idle"] = "";
    m_animpaths[animations]["IDLE"] = "";
    m_animpaths[animations]["used"] = "";
    m_animpaths[animations]["USED"] = "";

}
