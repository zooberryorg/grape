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

    QHash<QString, QString> foundCharInts = GrINI::getKeyValuesInSection(ini, charInts);
    GrINI::assignNewValuesToKeys(m_intchars, foundCharInts);

    QHash<QString, QString> foundAnimations = GrINI::getKeyValuesInSection(ini, animations);
    GrINI::assignNewValuesToKeys(m_animpaths, foundAnimations);

    QHash<QString, QString> foundIcons = GrINI::getKeyValuesInSection(ini, "Icon");
    GrINI::assignNewValuesToKeys(m_icon, foundIcons);

    QHash<QString, QString> foundGlobals = GrINI::getKeyValuesInSection(ini, globals);
    GrINI::assignNewValuesToKeys(m_globals, foundGlobals);

    QHash<QString, QString> foundDefaultLcid = GrINI::getKeyValuesInSection(ini, defaultLcid);
    GrINI::assignNewValuesToKeys(m_defaultlcid, foundDefaultLcid);

    QHash<QString, QString> found1033 = GrINI::getKeyValuesInSection(ini, _1033);
    GrINI::assignNewValuesToKeys(m_1033, found1033);
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
