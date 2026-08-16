#ifndef CPATH_H
#define CPATH_H

#include "cscenery.h"

class CPath : public CScenery
{
public:
    CPath(QString);
    void initMembers();
    void initCharInts();
    void initIcon();
};

#endif // CPATH_H
