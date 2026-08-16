#include "ctankfilter.h"


CTankFilter::CTankFilter(QString path)
    : CScenery(path)
{
    m_type = AssetType::TankFilter;
    initMembers();
    initCharInts();
    initIcon();
}

void CTankFilter::initMembers()
{

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
