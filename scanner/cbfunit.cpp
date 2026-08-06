#include "cbfunit.h"

CBFUnit::CBFUnit() {
    mConfig["cr_part1"]["ncolors"] = "";

    QString charInts = "Characteristics/Integers";
    mConfig[charInts]["cSlowRate"] = "";
    mConfig[charInts]["cMediumRate"] = "";
    mConfig[charInts]["cFastRate"] = "";
    mConfig[charInts]["cSlowAnimSpeed"] = "";
    mConfig[charInts]["cMediumAnimSpeed"] = "";
    mConfig[charInts]["cFastAnimSpeed"] = "";
    mConfig[charInts]["cMinHeight"] = "";
    mConfig[charInts]["cMaxHeight"] = "";
}
