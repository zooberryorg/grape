#include "cfence.h"


CFence::CFence(QString path)
    : CScenery(path)
{
    m_type = AssetType::Fence;
    initMembers();
    initCharInts();
    initIcon();
}

void CFence::initMembers()
{
    m_members.clear();
    m_members.append("fence");
}

void CFence::initCharInts()
{
    m_intchars[charInts]["cStrength"] = "";
    m_intchars[charInts]["cLife"] = "";
    m_intchars[charInts]["cDecayedLife"] = "";
    m_intchars[charInts]["cDecayedDelta"] = "";
    m_intchars[charInts]["cBreakSoundAtten"] = "";
    m_intchars[charInts]["cOpenSoundAtten"] = "";
    m_intchars[charInts]["cSeeThrough"] = "";
    m_intchars[charInts]["cIsJumpable"] = "";
    m_intchars[charInts]["cIsClimbable"] = "";
    m_intchars[charInts]["cIndestructible"] = "";
    m_intchars[charInts]["cIsElectrified"] = "";
    m_intchars[charInts]["cNoDrawWater"] = "";
}

void CFence::initIcon() {
    m_icon.clear();
    m_icon["Icon"]["Icon"] = "";
}
