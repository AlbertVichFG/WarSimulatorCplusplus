#include <iostream>

#include "Unit.h"
#include "Soldier.h"
#include "Tank.h"
#include "HorseMan.h"
#include "Army.h"
#include "Battle.h"

// Demana una quantitat de tropes per consola
int askQuantity(const std::string& unitName)
{
    int quantity;

    while (true)
    {
        std::cout << "Number of " << unitName << ": ";

        if (std::cin >> quantity && quantity >= 0)
        {
            return quantity;
        }

        // Si l'usuari introdueix un valor incorrecte,
        // netegem l'error i tornem a demanar la quantitat
        std::cout << "Invalid number. Try again.\n";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
    }
}

// Configura les unitats de cada exercit
void configureArmy(Army& army)
{
    std::cout << "\n===== " << army.getName()
              << " CONFIGURATION =====\n";

    int soldiers = askQuantity("Soldiers");
    int tanks = askQuantity("Tanks");
    int horsemen = askQuantity("Horsemen");

    // Creem els soldats
    for (int i = 0; i < soldiers; i++)
    {
        army.addUnit(new Soldier());
    }

    // Creem els tancs
    for (int i = 0; i < tanks; i++)
    {
        army.addUnit(new Tank());
    }

    // Creem els cavallers
    for (int i = 0; i < horsemen; i++)
    {
        army.addUnit(new HorseMan());
    }

    std::cout << "\nTotal units: "
              << army.getAliveCount() << "\n";
}

int main()
{
    std::cout << "=========================\n";
    std::cout << "      WAR SIMULATOR      \n";
    std::cout << "=========================\n";

    // Creem els dos exercits
    Army armyA("ARMY A");
    Army armyB("ARMY B");

    // Demanem les quantitats de tropes
    configureArmy(armyA);
    configureArmy(armyB);

    std::cout << "\nStarting battle...\n";

    // Creem i iniciem la batalla
    Battle battle(armyA, armyB);

    battle.start();

    return 0;
}