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
    m_intchars[charInts]["cStrength"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cLife"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cDecayedLife"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cDecayedDelta"] = { "", Group::Traits, Widget::Integer };
    m_intchars[charInts]["cBreakSoundAtten"] = { "", Group::Sounds, Widget::Integer };
    m_intchars[charInts]["cOpenSoundAtten"] = { "", Group::Sounds, Widget::Integer };
    m_intchars[charInts]["cSeeThrough"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cIsJumpable"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cIsClimbable"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cIndestructible"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cIsElectrified"] = { "", Group::Traits, Widget::Switch };
    m_intchars[charInts]["cNoDrawWater"] = { "", Group::Traits, Widget::Switch };
}

void CFence::initIcon() {
    m_icon.clear();
    m_icon["Icon"]["Icon"] = { "", Group::Graphics, Widget::LineText };
}

GrShared::SubtypeList CFence::subtypes() const
{
    return {
        { "f", "Fence" },
        { "g", "Gate" }
    };
}
