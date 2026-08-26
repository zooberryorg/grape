#include "cztunit.h"

CZTUnit::CZTUnit(QString path)
    : CBFUnit(path)
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        { 
            { "cPurchaseCost", { "", Group::Commerce, Widget::Integer } },
            { "cNameId", { "", Group::ID, Widget::IdPicker } },
            { "cHelpId", { "", Group::ID, Widget::IdPicker } },
            { "cMapFootprint", { "", Group::UI, Widget::Integer } },
            { "cSlowAnimSpeedWater", { "", Group::Graphics, Widget::Integer } },
            { "cFastAnimSpeedWater", { "", Group::Graphics, Widget::Integer } },
            { "cSwims", { "", Group::Traits, Widget::Switch } },
            { "cOnlyUnderwater", { "", Group::Traits, Widget::Switch } },
            { "cSkipTrickHappiness", { "", Group::Traits, Widget::Switch } },
            { "cSkipTrickChance", { "", Group::Traits, Widget::Switch } }
        }
    };
    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}
