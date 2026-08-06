#include "cbfunit.h"

CBFUnit::CBFUnit() {
    m_config["cr_part1"]["ncolors"] = "";

    QString charInts = "Characteristics/Integers";
    m_config[charInts]["cSlowRate"] = "";
    m_config[charInts]["cMediumRate"] = "";
    m_config[charInts]["cFastRate"] = "";
    m_config[charInts]["cSlowAnimSpeed"] = "";
    m_config[charInts]["cMediumAnimSpeed"] = "";
    m_config[charInts]["cFastAnimSpeed"] = "";
    m_config[charInts]["cMinHeight"] = "";
    m_config[charInts]["cMaxHeight"] = "";
}
