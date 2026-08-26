#ifndef CFENCE_H
#define CFENCE_H

#include "cscenery.h"

class CFence : public CScenery
{
public:
    CFence(QString);
    void initMembers();
    void initCharInts();
    void initIcon();
    GrShared::SubtypeList subtypes() const override;
};

#endif // CFENCE_H
