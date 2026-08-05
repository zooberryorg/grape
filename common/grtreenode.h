#ifndef GRTREENODE_H
#define GRTREENODE_H

#include <QList>

class GrTreeNode
{
public:
    explicit GrTreeNode(GrTreeNode* parentNode);
    ~GrTreeNode();

    void appendChild(GrTreeNode* child);

    GrTreeNode* child(int row) const;
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    GrTreeNode* parentNode() const;

private:
    QList<GrTreeNode*> m_childNodes;
    QStringList m_columnData;
    GrTreeNode* m_parentNode;
};

#endif // GRTREENODE_H
