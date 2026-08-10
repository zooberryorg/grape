/* MIT License
 *
 * Copyright (C) 2020 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include "grprojecttreemodel.h"
#include "grtreenode.h"
#include <QDebug>

GrProjectTreeModel::GrProjectTreeModel(GrTreeNode *root, QObject *parent)
    : QAbstractItemModel(parent)
    , m_root(root)
{
}

QVariant GrProjectTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return m_root->data(section);
    }
    return {};
}

QModelIndex GrProjectTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    GrTreeNode *parentNode = treeNodeFromIndex(parent);
    GrTreeNode *ptr = parentNode->child(row);
    return createIndex(row, column, ptr);
}

QModelIndex GrProjectTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return {};

    GrTreeNode *myNode = treeNodeFromIndex(index);
    GrTreeNode *parentNode = myNode->parentNode();
    if (parentNode == m_root)
        return {};

    int row = parentNode->row();
    return createIndex(row, 0, parentNode);
}

int GrProjectTreeModel::rowCount(const QModelIndex &parent) const
{
    GrTreeNode *data = treeNodeFromIndex(parent);
    return data->childCount();
}

int GrProjectTreeModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant GrProjectTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    GrTreeNode *node = treeNodeFromIndex(index);
    return node->data(index.column());
}
GrTreeNode *GrProjectTreeModel::treeNodeFromIndex(const QModelIndex &index) const
{
    if (!index.isValid())
        return m_root;
    else
        return static_cast<GrTreeNode *>(index.internalPointer());
}
