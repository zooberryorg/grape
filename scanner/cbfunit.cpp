#include "cbfunit.h"

CBFUnit::CBFUnit(QString path)
    : CEntity(path)
{
    m_intchars[charInts]["cSlowRate"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cMediumRate"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cFastRate"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cSlowAnimSpeed"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cMediumAnimSpeed"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cFastAnimSpeed"] = { "", Group::Graphics, Widget::Integer };
    m_intchars[charInts]["cMinHeight"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cMaxHeight"] = { "", Group::Traits, Widget::Integer };
}
