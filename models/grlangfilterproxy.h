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

        const QRegularExpression& re = filterRegularExpression();
        return sourceModel()->data(idIndex).toString().contains(re)
            || sourceModel()->data(valueIndex).toString().contains(re);
    }
};

#endif // GRLANGFILTERPROXY_H
