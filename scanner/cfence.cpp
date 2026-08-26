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
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cStrength", { "", Group::Traits, Widget::Integer } },
            { "cLife", { "", Group::Traits, Widget::Integer } },
            { "cDecayedLife", { "", Group::Traits, Widget::Integer } },
            { "cDecayedDelta", { "", Group::Traits, Widget::Integer } },
            { "cBreakSoundAtten", { "", Group::Sounds, Widget::Integer } },
            { "cOpenSoundAtten", { "", Group::Sounds, Widget::Integer } },
            { "cSeeThrough", { "", Group::Traits, Widget::Switch } },
            { "cIsJumpable", { "", Group::Traits, Widget::Switch } },
            { "cIsClimbable", { "", Group::Traits, Widget::Switch } },
            { "cIndestructible", { "", Group::Traits, Widget::Switch } },
            { "cIsElectrified", { "", Group::Traits, Widget::Switch } },
            { "cNoDrawWater", { "", Group::Traits, Widget::Switch } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}

void CFence::initIcon() {
    m_icon.clear();
    GrINI::SectionTemplate tmpl {
        "Icon",
        {
            { "Icon", { "", Group::Graphics, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_icon, tmpl, subtypes());
}

GrShared::SubtypeList CFence::subtypes() const
{
    return {
        { "f", "Fence" },
        { "g", "Gate" }
    };
}
