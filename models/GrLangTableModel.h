#ifndef GRLANGTABLEMODEL_H
#define GRLANGTABLEMODEL_H

#include <QAbstractTableModel>

class GrLangTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit GrLangTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // GRLANGTABLEMODEL_H
