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
    m_intchars[charInts]["cStartingHealth"] = "";
    m_intchars[charInts]["cDecayedHealth"] = "";
    m_intchars[charInts]["cDecayTime"] = "";
    m_intchars[charInts]["cFilterDelay"] = "";
    m_intchars[charInts]["cFilterUpkeep"] = "";
    m_intchars[charInts]["cFilterCleanAmount"] = "";
    m_intchars[charInts]["cFilterDecayedCleanAmount"] = "";
    m_intchars[charInts]["cPriceFactor"] = "";
}

void CTankFilter::initIcon()
{
    m_icon.clear();
    m_icon[icons]["Icon"] = "";
}

void CTankFilter::initCharStrings()
{
    m_strchars[charStrings]["cInfoImageName"] = "";
}

void CTankFilter::initFilterSounds()
{
    m_filtersounds[filterSounds]["cHealthySounds"] = "";
    m_filtersounds[filterSounds]["cHealthyAtten"] = "";
    m_filtersounds[filterSounds]["cDecayedSound"] = "";
    m_filtersounds[filterSounds]["cDecayedAtten"] = "";

}
