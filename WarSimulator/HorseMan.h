#pragma once
#include "Unit.h"

class HorseMan : public Unit
{
public:
    HorseMan();

    int calculateDamage() const override;
};