#include "grtreenode.h"
#include <qvariant.h>

// GrTreeNode::GrTreeNode() {}

GrTreeNode::GrTreeNode(QString data, GrTreeNode *parentNode)
    : m_columnData(data)
    , m_parentNode(parentNode)
{

}

GrTreeNode::~GrTreeNode()
{
    qDeleteAll(m_childNodes);
}

void GrTreeNode::appendChild(GrTreeNode *child)
{
    m_childNodes.append(child);
}

GrTreeNode *GrTreeNode::child(int row) const
{
    return m_childNodes.at(row);
}

int GrTreeNode::childCount() const
{
    return m_childNodes.count();
}

int GrTreeNode::columnCount() const
{
    return 1; // note: no plan for additional columns but change QString to QStringList if more needed
}

QVariant GrTreeNode::data() const
{
    QVariant v = QVariant();
    v.setValue(m_columnData);
    return v;
}

int GrTreeNode::row() const
{

}

GrTreeNode *GrTreeNode::parentNode() const
{

}
