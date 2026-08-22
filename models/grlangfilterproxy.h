#ifndef GRLANGFILTERPROXY_H
#define GRLANGFILTERPROXY_H

#include <QSortFilterProxyModel>

class GrLangFilterProxy : public QSortFilterProxyModel
{
public:
    using QSortFilterProxyModel::QSortFilterProxyModel;

    void setDllFilter(const QString& dllName)
    {
        m_dllFilter = dllName;
        invalidateFilter();
    }

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override
    {
        QModelIndex idIndex = sourceModel()->index(sourceRow, 0, sourceParent);
        QModelIndex valueIndex = sourceModel()->index(sourceRow, 1, sourceParent);

        // search first two columns for text
        const QRegularExpression& re = filterRegularExpression();
        bool textMatches = sourceModel()->data(idIndex).toString().contains(re)
            || sourceModel()->data(valueIndex).toString().contains(re);

        if ( !textMatches ) {
            return false;
        }

        // match combo box filter in third column
        if (!m_dllFilter.isEmpty()) {
            QModelIndex dllIndex = sourceModel()->index(sourceRow, 2, sourceParent);
            if (sourceModel()->data(dllIndex).toString() != m_dllFilter) {
                return false;
            }
        }

        return true;
    }

private:
    QString m_dllFilter;
};

#endif // GRLANGFILTERPROXY_H
