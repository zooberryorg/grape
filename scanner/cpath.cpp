#include "cpath.h"


CPath::CPath(QString path)
    : CScenery(path)
{
    m_type = AssetType::Path;
    initMembers();
    initCharInts();
}

void CPath::initMembers()
{
    m_members.clear();
    m_members.append("paths");
}

void CPath::initCharInts()
{
    GrINI::SectionTemplate tmpl {
        "Characteristics/Integers",
        {
            { "cMaterial", { "", Group::Traits, Widget::Switch } }
        }
    };

    GrINI::registerSubtypes(m_intchars, tmpl, subtypes());
}

void CPath::initIcon() {
    m_icon.clear();

    GrINI::SectionTemplate tmpl {
        "Icon",
        {
            { "Icon", { "", Group::Graphics, Widget::LineText } }
        }
    };
    GrINI::registerSubtypes(m_icon, tmpl, subtypes());
}
