#include "cztunit.h"

CZTUnit::CZTUnit(QString path)
    : CBFUnit(path)
{
    m_intchars[charInts]["cPurchaseCost"] = { "", Group::Commerce, Widget::Integer };
    m_intchars[charInts]["cNameId"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cHelpId"] = { "", Group::ID, Widget::IdPicker };
    m_intchars[charInts]["cMapFootprint"] = { "", Group::UI, Widget::Integer };
    m_intchars[charInts]["cSlowAnimSpeedWater"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cFastAnimSpeedWater"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cSwims"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cOnlyUnderwater"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cSkipTrickHappiness"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cSkipTrickChance"] = { "", Group::Traits, Widget::Switch };

}
