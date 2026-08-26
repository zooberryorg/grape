#include "cscenery.h"
#include "grini.h"

CScenery::CScenery(QString path)
    : CEntity(path)
{
    m_type = AssetType::Scenery;
    initProjectName();
    initGlobals();
    initAnimations();
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

    GrINI::loadConfig( ini,
        {
            &m_intchars,
            &m_animations,
            &m_globals,
            &m_defaultlcid,
            &m_1033
        }
    );

    QHash<QString, QString> foundIcons = GrINI::getKeyValuesInSection(ini, icons);
    for ( const QString& value : foundIcons ) {
        if ( value.contains("SE") ) {
            m_icon[icons]["IconSE"].v = value;
        }
        else if ( value.contains("SW") ) {
            m_icon[icons]["IconSW"].v = value;
        }
        else if ( value.contains("NE") ) {
            m_icon[icons]["IconNE"].v = value;
        }
        else if ( value.contains("NW") ) {
            m_icon[icons]["IconNW"].v = value;
        }
    }
}

void CScenery::save()
{

}

void CScenery::initGlobals()
{
    m_globals[globals]["Type"] = { "", Group::ID, Widget::IdPicker };
}

void CScenery::initIcon()
{
    m_icon[icons]["IconSE"] = { "", Group::Graphics, Widget::LineText };
    m_icon[icons]["IconSW"] = { "", Group::Graphics, Widget::LineText };
    m_icon[icons]["IconNW"] = { "", Group::Graphics, Widget::LineText };
    m_icon[icons]["IconNE"] = { "", Group::Graphics, Widget::LineText };

}

void CScenery::initMembers()
{
    m_members.append("scenery");
}

void CScenery::initCharInts()
{
    m_intchars[charInts]["cPurchaseCost"] = { "", Group::Commerce, Widget::Integer };
    m_intchars[charInts]["cHelpId"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cNameId"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cHabitat"] = { "", Group::Terrain, Widget::IdPicker };
    m_intchars[charInts]["cLocation"] = { "", Group::Terrain, Widget::IdPicker };
    m_intchars[charInts]["cEra"] = { "", Group::Terrain, Widget::IdPicker };
    m_intchars[charInts]["cMaxFoodUnits"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cStink"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cEstheticWeight"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cSelectable"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cDeletable"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cFoliage"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cAutoRotate"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cLand"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cSwims"] = { "", Group::Traits, Widget::Switch }; // not in game files
    m_intchars[charInts]["cUnderwater"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cSurface"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cSubmerge"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cOnlySwims"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cNeedsConfirm"] = { "", Group::UI, Widget::Switch };
    m_intchars[charInts]["cGawkOnlyFromFront"] = { "", Group::Slots, Widget::Switch };
    m_intchars[charInts]["cDeadOnLand"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cDeadOnFlatWater"] = { "", Group::Traits, Widget::Switch }; // not in game files
    m_intchars[charInts]["cDeadUnderwater"] = { "", Group::Traits, Widget::Switch }; // not in game files
    m_intchars[charInts]["cUsesTreeRubble"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cForcesSceneryRubble"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cBlocksLos"] = { "", Group::Traits, Widget::Switch };
}

void CScenery::initDefaultLcid()
{
    m_defaultlcid[defaultLcid]["LCID"] = { "", Group::ID, Widget::LineText };
}

void CScenery::init1033()
{
    m_1033[_1033]["cGeneralInfoFileName"] = { "", Group::Graphics, Widget::LineText };
    m_1033[_1033]["cLongHelp"] = { "", Group::ID, Widget::MultilineText };
    m_1033[_1033]["cName"] = { "", Group::ID, Widget::LineText };
    m_1033[_1033]["cTheString"] = { "", Group::ID, Widget::LineText };
}

void CScenery::initAnimations()
{
    m_animations[animations]["idle"] = { "", Group::Graphics, Widget::LineText };
    m_animations[animations]["IDLE"] = { "", Group::Graphics, Widget::LineText };
    m_animations[animations]["used"] = { "", Group::Graphics, Widget::LineText };
    m_animations[animations]["USED"] = { "", Group::Graphics, Widget::LineText };

}
