#ifndef CANIMAL_H
#define CANIMAL_H

#include "cztunit.h"

class CAnimal : public CZTUnit
{
public:
    CAnimal(QString);
    void load() override;
};

#endif // CANIMAL_H
