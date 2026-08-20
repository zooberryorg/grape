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
#include "grgfx.h"

GrProjectTreeModel::GrProjectTreeModel(QMap<AssetType, QVector<GrAsset*>> groupTypes, QObject *parent)
    : QAbstractItemModel(parent)
    , m_grouptypes(groupTypes)
    , m_keys(groupTypes.keys())
{
}

QModelIndex GrProjectTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if ( !parent.isValid() ) {
        // found a group
        if ( row < 0 || row >= m_keys.size() )
            return QModelIndex();
        return createIndex(row, column, quintptr(-1));
    }

    // child
    const AssetType type = m_keys.at(parent.row());
    const auto& assets = m_grouptypes.value(type);

    if ( row < 0 || row >= assets.size() ) {
        return QModelIndex();
    }

    return createIndex(row, column, quintptr(type));
}

QModelIndex GrProjectTreeModel::parent(const QModelIndex &index) const
{
    if ( !index.isValid() || index.internalId() == quintptr(-1) ) {
        return QModelIndex();
    }

    const AssetType type = static_cast<AssetType>(index.internalId());
    const int groupRow = m_keys.indexOf(type);
    return createIndex(groupRow, 0, quintptr(-1));
}

int GrProjectTreeModel::rowCount(const QModelIndex &parent) const
{
    if ( !parent.isValid() ) {
        // num of groups
        return m_keys.size();
    }

    if ( parent.internalId() == quintptr(-1)) {
        // parent is a group + ret num of assets inside
        const AssetType type = m_keys.at(parent.row());
        return m_grouptypes.value(type).size();
    }

    // parent is a leaf (asset)
    return 0;
}

int GrProjectTreeModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QVariant GrProjectTreeModel::data(const QModelIndex &index, int role) const
{
    // if invis root, return empty QVariant
    if ( !index.isValid() || index.column() != 0 )
        return QVariant();

    if ( index.internalId() == quintptr(-1) ) {
        const AssetType type = m_keys.at(index.row());
        if ( role == Qt::DisplayRole )
        {
            return GrShared::TypeToString(type);
        } if ( role == Qt::DecorationRole ) {
            return groupIcon(type);
        }
        return QVariant();
    }

    const AssetType type = static_cast<AssetType>(index.internalId());
    GrAsset* asset = m_grouptypes.value(type).at(index.row());

    if (role == Qt::DisplayRole) {
        return asset->name();
    }
    if (role == Qt::DecorationRole) {
        return GrGfx::setSvgColor(":/icons/file-smile.svg", "#fff", 30, 30);
    }
    if (role == Qt::UserRole) {
        return QVariant::fromValue( asset );
    }
    return QVariant();
}

QVariant GrProjectTreeModel::groupIcon(const AssetType& type) const
{
    switch ( type ) {
        case AssetType::Animal:
            return GrGfx::setSvgColor(":/icons/paw.svg", "#fff", 30, 30);
        case AssetType::Building:
            return GrGfx::setSvgColor(":/icons/building.svg", "#fff", 30, 30);
        case AssetType::Fence:
            return GrGfx::setSvgColor(":/icons/fence.svg", "#fff", 30, 30);
        case AssetType::Path:
            return GrGfx::setSvgColor(":/icons/path.svg", "#fff", 30, 30);
        case AssetType::Scenery:
            return GrGfx::setSvgColor(":/icons/fountain.svg", "#fff", 30, 30);
        case AssetType::Foliage:
            return GrGfx::setSvgColor(":/icons/tree.svg", "#fff", 30, 30);

        default:
            return GrGfx::setSvgColor(":/icons/file-smile.svg", "#fff", 30, 30);
    }
}

void GrProjectTreeModel::setAssets(QMap<AssetType, QVector<GrAsset *>> groupTypes)
{
    beginResetModel();
    m_grouptypes = groupTypes;
    m_keys = groupTypes.keys();
    endResetModel();
}

void GrProjectTreeModel::insertProject(GrAsset* asset)
{
    const AssetType type = asset->getType();
    int groupRow = m_keys.indexOf(type);

    // group doesnt exist yet so find location and sort by enum index
    if ( groupRow == -1 ) {
        groupRow = 0;
        while ( groupRow < m_keys.size() && m_keys.at(groupRow) < type )
            ++groupRow;

        beginInsertRows(QModelIndex(), groupRow, groupRow);
        m_keys.insert(groupRow, type);
        m_grouptypes.insert(type, {});
        endInsertRows();
    }

    const QModelIndex groupIndex = index(groupRow, 0, QModelIndex());
    const int childRow = m_grouptypes[type].size();

    beginInsertRows(groupIndex, childRow, childRow);
    m_grouptypes[type].append(asset);
    endInsertRows();
}
