#ifndef GRLANGFILTERPROXY_H
#define GRLANGFILTERPROXY_H

#include <QSortFilterProxyModel>

class GrLangFilterProxy : public QSortFilterProxyModel
{
public:
    using QSortFilterProxyModel::QSortFilterProxyModel;

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override
    {
        QModelIndex idIndex = sourceModel()->index(sourceRow, 0, sourceParent);
        QModelIndex valueIndex = sourceModel()->index(sourceRow, 1, sourceParent);

        const QString pattern = filterRegularExpression().pattern();
        return sourceModel()->data(idIndex).toString().contains(pattern, Qt::CaseInsensitive)
            || sourceModel()->data(valueIndex).toString().contains(pattern, Qt::CaseInsensitive);
    }
};

#endif // GRLANGFILTERPROXY_H
