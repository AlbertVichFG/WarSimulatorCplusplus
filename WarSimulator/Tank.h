#pragma once
#include "Unit.h"

class Tank : public Unit
{
public:
    Tank();

    int calculateDamage() const override;
};