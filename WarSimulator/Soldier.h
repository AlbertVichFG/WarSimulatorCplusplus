#pragma once

#include "Unit.h"

// Soldier hereta de Unit
class Soldier : public Unit
{
public:
    Soldier();

    // Implementa la funció abstracta de la classe pare
    int calculateDamage() const override;
};