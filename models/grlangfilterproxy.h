#ifndef GRLANGFILTERPROXY_H
#define GRLANGFILTERPROXY_H

#include <QSortFilterProxyModel>

class GrLangFilterProxy : public QSortFilterProxyModel
{
public:
    explicit GrLangFilterProxy(QObject *parent = nullptr);
};

#endif // GRLANGFILTERPROXY_H
