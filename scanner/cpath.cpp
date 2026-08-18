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
    m_intchars[charInts]["cMaterial"] = { "", Group::Traits, Widget::Switch };
}

void CPath::initIcon() {
    m_icon.clear();
    m_icon["Icon"]["Icon"] = { "", Group::Graphics, Widget::LineText };
}
