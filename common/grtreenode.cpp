#include "grtreenode.h"

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

}

int GrTreeNode::childCount() const
{

}

int GrTreeNode::columnCount() const
{

}

QVariant GrTreeNode::data(int column) const
{

}

int GrTreeNode::row() const
{

}

GrTreeNode *GrTreeNode::parentNode() const
{

}
