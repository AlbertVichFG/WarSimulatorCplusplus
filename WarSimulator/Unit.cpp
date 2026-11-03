#include "Unit.h"


// Constructor: assigna els valors inicials
Unit::Unit(const std::string& name, int heal, int armor,
           int dmg, float attackSpeed)
    : name(name),
      heal(heal),
      armor(armor),
      dmg(dmg),
      attackSpeed(attackSpeed),
      attackProgress(0.0f)
{
}

// Destructor virtual
Unit::~Unit() = default;

std::string Unit::getName() const
{
    return name;
}

int Unit::getHeal() const
{
    return heal;
}

int Unit::getArmor() const
{
    return armor;
}

bool Unit::isAlive() const
{
    return heal > 0;
}

// Calcula el dany final després del blindatge
void Unit::getDmg(int incomingDamage)
{
    int finalDamage = incomingDamage - armor;

    // El dany mínim sempre serà 1
    if (finalDamage < 1)
        finalDamage = 1;

    heal -= finalDamage;

    // Evitem que la vida sigui negativa
    if (heal < 0)
        heal = 0;
}

// Calcula els atacs disponibles durant aquesta ronda
int Unit::getAttacksThisRound()
{
    attackProgress += attackSpeed;

    // static_cast<int> converteix el decimal en enter
    int attacks = static_cast<int>(attackProgress);

    // Conservem la part decimal per a la ronda següent
    attackProgress -= attacks;

    return attacks;
}