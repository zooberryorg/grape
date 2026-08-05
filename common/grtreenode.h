#ifndef GRTREENODE_H
#define GRTREENODE_H

#include <QList>

class GrTreeNode
{
public:
    explicit GrTreeNode(QString data, GrTreeNode* parentNode);
    ~GrTreeNode();

    void appendChild(GrTreeNode* child);

    GrTreeNode* child(int row) const;
    int childCount() const;
    int columnCount() const;
    QVariant data() const;
    int row() const;
    GrTreeNode* parentNode() const;

private:
    QList<GrTreeNode*> m_childNodes;
    QString m_columnData; // only one column for this data
    GrTreeNode* m_parentNode;
};

#endif // GRTREENODE_H
