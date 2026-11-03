#pragma once

#include <string>
#include <vector>
#include "Unit.h"

class Army
{
private:
    std::string name;

    // Vector de punters: permet guardar diferents tipus d'unitats
    // que hereten de la mateixa classe Unit
    std::vector<Unit*> units;

public:
    Army(const std::string& name);

    // Destructor: allibera la memòria de les unitats
    ~Army();

    // Afegeix una unitat a l'exèrcit
    void addUnit(Unit* unit);

    std::string getName() const;

    // Retorna totes les unitats de l'exèrcit
    const std::vector<Unit*>& getUnits() const;

    // Comprova quantes unitats continuen vives
    int getAliveCount() const;

    // Comprova quantes unitats han mort
    int getCasualtiesCount() const;

    // Comprova si l'exèrcit encara pot combatre
    bool hasLivingUnits() const;
};