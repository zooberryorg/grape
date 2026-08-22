#include "grlangtablemodel.h"

GrLangTableModel::GrLangTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
}

void GrLangTableModel::setEntries(QString, QVector<StringEntry> entries)
{
    beginResetModel();
    m_entries = std::move(entries);
    endResetModel();
}

int GrLangTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_entries.size();
}

int GrLangTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
}

QVariant GrLangTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_entries.size())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        const StringEntry &entry = m_entries.at(index.row());
        switch (index.column()) {
            case 0: return entry.id;
            case 1: return entry.value;
            case 2: return entry.dllFileName;
        }
    }
    return QVariant();
}

QVariant GrLangTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
        case 0: return "ID";
        case 1: return "Value";
        case 2: return "File Name";
    }
    return QVariant();
}
