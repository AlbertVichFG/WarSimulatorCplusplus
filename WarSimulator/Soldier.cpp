#include "Soldier.h"

// Inicialitzem les característiques del soldat
Soldier::Soldier()
    : Unit("Soldier", 100, 2, 20, 1.0f)
{
}

// Retorna el dany del soldat
int Soldier::calculateDamage() const
{
    return dmg;
}