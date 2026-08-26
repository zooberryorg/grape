#include "ctankfilter.h"
#include "grini.h"

CTankFilter::CTankFilter(QString path)
    : CScenery(path)
{
    m_type = AssetType::TankFilter;
    initMembers();
    initCharInts();
    initIcon();
    initCharStrings();
}

void CTankFilter::load() {
    CSimpleIniA ini;
    int rc = ini.LoadFile(m_cpath.toStdString().c_str());
    if ( rc < 0 ) {
        // error handling here
    }

    GrINI::loadConfig(ini, {
        &m_intchars,
        &m_animpaths,
        &m_icon,
        &m_globals,
        &m_defaultlcid,
        &m_1033
    });
}

void CTankFilter::initMembers()
{
    m_members.clear();
    m_members.append("habitatfences");
    m_members.append("highfence");
    m_members.append("fence");
    m_members.append("aqua");
}

void CTankFilter::initCharInts()
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cStartingHealth", { "", Group::Traits, Widget::Integer } },
            { "cDecayedHealth", { "", Group::Traits, Widget::Integer } },
            { "cDecayTime", { "", Group::Traits, Widget::Integer } },
            { "cFilterDelay", { "", Group::Traits, Widget::Integer } },
            { "cFilterUpkeep", { "", Group::Traits, Widget::Integer } },
            { "cFilterCleanAmount", { "", Group::Traits, Widget::Integer } },
            { "cFilterDecayedCleanAmount", { "", Group::Traits, Widget::Integer } },
            { "cPriceFactor", { "", Group::Commerce, Widget::Integer } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}

void CTankFilter::initIcon()
{
    m_icon.clear();
    m_icon[icons]["Icon"] = { "", Group::Graphics, Widget::LineText };
}

void CTankFilter::initCharStrings()
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Strings",
        {
            { "cInfoImageName", { "", Group::Graphics, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_strchars, tmpl, subtypes());
}

void CTankFilter::initFilterSounds()
{
    GrINI::SectionTemplate tmpl {
        "FilterSounds",
        {
            { "cHealthySounds", { "", Group::Sounds, Widget::LineText } },
            { "cHealthyAtten", { "", Group::Sounds, Widget::Integer } },
            { "cDecayedSound", { "", Group::Sounds, Widget::LineText } },
            { "cDecayedAtten", { "", Group::Sounds, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_filtersounds, tmpl, subtypes());
}
}
