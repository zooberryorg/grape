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
            m_icon[""][icons]["IconSE"].v = value;
        }
        else if ( value.contains("SW") ) {
            m_icon[""][icons]["IconSW"].v = value;
        }
        else if ( value.contains("NE") ) {
            m_icon[""][icons]["IconNE"].v = value;
        }
        else if ( value.contains("NW") ) {
            m_icon[""][icons]["IconNW"].v = value;
        }
    }
}

void CScenery::save()
{

}

void CScenery::initGlobals()
{
    GrINI::SectionTemplate tmpl {
        "Global",
        {
            { "Type", { "", Group::ID, Widget::IdPicker } }
        }
    };
    GrINI::registerSubtypes(m_globals, tmpl, subtypes());
}

void CScenery::initIcon()
{
    GrINI::SectionTemplate tmpl {
        "Icon",
        {
            { "IconSE", { "", Group::Graphics, Widget::LineText } },
            { "IconSW", { "", Group::Graphics, Widget::LineText } },
            { "IconNW", { "", Group::Graphics, Widget::LineText } },
            { "IconNE", { "", Group::Graphics, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_icon, tmpl, subtypes());
}

void CScenery::initMembers()
{
    m_members.append("scenery");
}

void CScenery::initCharInts()
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cPurchaseCost", { "", Group::Commerce, Widget::Integer } },
            { "cHelpId", { "", Group::ID, Widget::IdPicker } },
            { "cNameId", { "", Group::ID, Widget::IdPicker } },
            { "cHabitat", { "", Group::Terrain, Widget::IdPicker } },
            { "cLocation", { "", Group::Terrain, Widget::IdPicker } },
            { "cEra", { "", Group::Terrain, Widget::IdPicker } },
            { "cMaxFoodUnits", { "", Group::Traits, Widget::Integer } },
            { "cStink", { "", Group::Traits, Widget::Switch } },
            { "cEstheticWeight", { "", Group::Traits, Widget::Integer } },
            { "cSelectable", { "", Group::UI, Widget::Switch } },
            { "cDeletable", { "", Group::UI, Widget::Switch } },
            { "cFoliage", { "", Group::Traits, Widget::Switch } },
            { "cAutoRotate", { "", Group::UI, Widget::Switch } },
            { "cLand", { "", Group::Traits, Widget::Switch } },
            { "cSwims", { "", Group::Traits, Widget::Switch } },
            { "cUnderwater", { "", Group::Traits, Widget::Switch } },
            { "cSurface", { "", Group::Traits, Widget::Switch } },
            { "cSubmerge", { "", Group::Traits, Widget::Switch } },
            { "cOnlySwims", { "", Group::Traits, Widget::Switch } },
            { "cNeedsConfirm", { "", Group::UI, Widget::Switch } },
            { "cGawkOnlyFromFront", { "", Group::Slots, Widget::Switch } },
            { "cDeadOnLand", { "", Group::Traits, Widget::Switch } },
            { "cDeadOnFlatWater", { "", Group::Traits, Widget::Switch } },
            { "cDeadUnderwater", { "", Group::Traits, Widget::Switch } },
            { "cUsesTreeRubble", { "", Group::Traits, Widget::Switch } },
            { "cForcesSceneryRubble", { "", Group::Traits, Widget::Switch } },
            { "cBlocksLos", { "", Group::Traits, Widget::Switch } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}

void CScenery::initDefaultLcid()
{
    GrINI::SectionTemplate tmpl {
        "DefaultLCID",
        {
            { "LCID", { "", Group::ID, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_defaultlcid, tmpl, subtypes());
}

void CScenery::init1033()
{
    GrINI::SectionTemplate tmpl {
        "1033",
        {
            { "cGeneralInfoFileName", { "", Group::Graphics, Widget::LineText } },
            { "cLongHelp", { "", Group::ID, Widget::MultilineText } },
            { "cName", { "", Group::ID, Widget::LineText } },
            { "cTheString", { "", Group::ID, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_1033, tmpl, subtypes());
}
void CScenery::initAnimations()
{
    GrINI::SectionTemplate tmpl {
        "Animations",
        {
            { "idle", { "", Group::Graphics, Widget::LineText } },
            { "IDLE", { "", Group::Graphics, Widget::LineText } },
            { "used", { "", Group::Graphics, Widget::LineText } },
            { "USED", { "", Group::Graphics, Widget::LineText } }
        }
    };

    GrINI::registerSubtypes(m_animations, tmpl, subtypes());
}

GrShared::Config CScenery::allSections()
{
    return {
        &m_icon,
        &m_intchars,
        &m_animations,
        &m_globals,
        &m_1033,
    };
}
