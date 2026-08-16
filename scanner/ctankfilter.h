#ifndef CTANKFILTER_H
#define CTANKFILTER_H

#include "cscenery.h"

class CTankFilter : public CScenery
{
public:
    CTankFilter(QString);
    void initMembers();
    void initCharInts();
    void initIcon();
    void initCharStrings();
    void initFilterSounds();
};

#endif // CTANKFILTER_H
