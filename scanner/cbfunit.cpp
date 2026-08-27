#include "cbfunit.h"

CBFUnit::CBFUnit(QString path)
    : CEntity(path)
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cSlowRate", { "", Group::Graphics, Widget::Integer } },
            { "cMediumRate", { "", Group::Graphics, Widget::Integer } },
            { "cFastRate", { "", Group::Graphics, Widget::Integer } },
            { "cSlowAnimSpeed", { "", Group::Graphics, Widget::Integer } },
            { "cMediumAnimSpeed", { "", Group::Graphics, Widget::Integer } },
            { "cFastAnimSpeed", { "", Group::Graphics, Widget::Integer } },
            { "cMinHeight", { "", Group::Traits, Widget::Integer } },
            { "cMaxHeight", { "", Group::Traits, Widget::Integer } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}
