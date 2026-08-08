#include "cztunit.h"

CZTUnit::CZTUnit(QString path)
    : CBFUnit(path)
{
    m_intchars[charInts]["cPurchaseCost"] = "";
    m_intchars[charInts]["cNameId"] = "";
    m_intchars[charInts]["cHelpId"] = "";
    m_intchars[charInts]["cMapFootprint"] = "";
    m_intchars[charInts]["cSlowAnimSpeedWater"] = "";
    m_intchars[charInts]["cFastAnimSpeedWater"] = "";
    m_intchars[charInts]["cSwims"] = "";
    m_intchars[charInts]["cOnlyUnderwater"] = "";
    m_intchars[charInts]["cSkipTrickHappiness"] = "";
    m_intchars[charInts]["cSkipTrickChance"] = "";

}
