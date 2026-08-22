#ifndef GRLANGTABLEMODEL_H
#define GRLANGTABLEMODEL_H

#include <QAbstractTableModel>
#include "grpe.h"

using StringEntry = GrPE::Entry;

class GrLangTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit GrLangTableModel(QObject *parent = nullptr);

    void setEntries(QString, QVector<StringEntry> entries);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QVector<StringEntry> m_entries;
};

#endif // GRLANGTABLEMODEL_H
