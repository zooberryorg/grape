#ifndef GRICON_H
#define GRICON_H

#include <QIcon>

class GrIcon
{
public:
    GrIcon();
    static QIcon setColor(const QString&);
    static QIcon setSize(int, int);
};

#endif // GRICON_H
