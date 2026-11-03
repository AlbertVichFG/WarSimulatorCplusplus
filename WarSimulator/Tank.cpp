#include "Tank.h"


// Inicialitzem les característiques del tanc
Tank::Tank()
    : Unit("Tank", 250, 20, 60, 0.5f)
{
}

int Tank::calculateDamage() const
{
    return dmg;
}