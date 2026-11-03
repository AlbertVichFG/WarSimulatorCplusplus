#include "Army.h"


// Constructor: assigna el nom de l'exèrcit
Army::Army(const std::string& name)
    : name(name)
{
}

// Destructor: elimina totes les unitats de la memòria
Army::~Army()
{
    for (Unit* unit : units)
    {
        delete unit;
    }
}

// Afegeix una unitat al vector
void Army::addUnit(Unit* unit)
{
    if (unit != nullptr)
    {
        units.push_back(unit);
    }
}

std::string Army::getName() const
{
    return name;
}

const std::vector<Unit*>& Army::getUnits() const
{
    return units;
}

// Comptem les unitats que continuen vives
int Army::getAliveCount() const
{
    int count = 0;

    for (Unit* unit : units)
    {
        if (unit->isAlive())
        {
            count++;
        }
    }

    return count;
}

// Comptem les baixes
int Army::getCasualtiesCount() const
{
    int count = 0;

    for (Unit* unit : units)
    {
        if (!unit->isAlive())
        {
            count++;
        }
    }

    return count;
}

// Comprova si encara queda alguna unitat viva
bool Army::hasLivingUnits() const
{
    return getAliveCount() > 0;
}