#include "HorseMan.h"

// Inicialitzem les característiques del cavaller
HorseMan::HorseMan()
    : Unit("Horseman", 140, 8, 30, 1.5f)
{
}

int HorseMan::calculateDamage() const
{
    return dmg;
}