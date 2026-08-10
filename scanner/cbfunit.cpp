#include "cbfunit.h"

CBFUnit::CBFUnit(QString path)
    : CEntity(path)
{
    QString charInts = "Characteristics/Integers";
    m_intchars[charInts]["cSlowRate"] = "";
    m_intchars[charInts]["cMediumRate"] = "";
    m_intchars[charInts]["cFastRate"] = "";
    m_intchars[charInts]["cSlowAnimSpeed"] = "";
    m_intchars[charInts]["cMediumAnimSpeed"] = "";
    m_intchars[charInts]["cFastAnimSpeed"] = "";
    m_intchars[charInts]["cMinHeight"] = "";
    m_intchars[charInts]["cMaxHeight"] = "";
}
