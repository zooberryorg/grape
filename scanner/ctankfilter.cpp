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
    m_intchars[charInts]["cStartingHealth"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cDecayedHealth"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cDecayTime"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cFilterDelay"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cFilterUpkeep"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cFilterCleanAmount"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cFilterDecayedCleanAmount"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cPriceFactor"] = { "", Group::Commerce, Widget::Integer };
}

void CTankFilter::initIcon()
{
    m_icon.clear();
    m_icon[icons]["Icon"] = { "", Group::Graphics, Widget::LineText };
}

void CTankFilter::initCharStrings()
{
    m_strchars[charStrings]["cInfoImageName"] = { "", Group::Graphics, Widget::LineText };
}

void CTankFilter::initFilterSounds()
{
    m_filtersounds[filterSounds]["cHealthySounds"] = { "", Group::Sounds, Widget::LineText };
    m_filtersounds[filterSounds]["cHealthyAtten"] = { "", Group::Sounds, Widget::Integer };
    m_filtersounds[filterSounds]["cDecayedSound"] = { "", Group::Sounds, Widget::LineText };
    m_filtersounds[filterSounds]["cDecayedAtten"] = { "", Group::Sounds, Widget::LineText };

}
