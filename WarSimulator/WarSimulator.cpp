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
    
    
/*    APUNTS!!
 *    auto tropa = new Unit(Unit::soldadoRaso); no funciona perque jo no tinc d'això
 *    
 *    //això es dif
    using tropa = std::unique_ptr<Unit>;
    tropa Artilleria = std::make_unique<Soldier>(Unit::Artilleria,50);
    tropa Sniper = std::make_unique<Soldier>(Unit::Sniper,20);
    
    Aixi creem nova unitat -> lo millor seria posar en el enum tots els parametres
    No hi ha unitat incognita per aixo agafem artilleria i nomñes canvia el nom!!
    topa UnidadIncognita = std::make_unique<Soldier>(Unit::Atrilleria, 3);
    
    tropa soldier3
    
    Artilleria ->AddTrop();
    std::vector<Unit> exercit;
    exercit.push_back(Artilleria)
    
    //
    
MAP (mateix que un dictionari a C#
Key y un valor

map<string, int>exemple;
exemple.insert(pair<string, int>("Ejercito",1));
exemple.insert(pair<string, int>("Pokemons",151));

cout<<"Ejercito: "<<ejemplo["Pokemons"] <<endl;

map <string,string> catala;
map <string,string> english;

catala.insert(pai<string,string>("Dialogo1", "Hola mon"));
english.insert(pai<string,string>("Dialogo1", "Hello world"));

//SET (una llista on no es pot repetir el valor

set<string> habilitats;
habilitats.insert("BolaDeFoc");
habilitats.insert("Curarse");
habilitats.insert("BolaDeFoc");

cout << habilitats.size();



//          Estan Ordenats?            Poden Tenir Valors Repetits?
    
Vector            Si                               Si
    
MAP               NO               No es poden repetir Keys, valors si

SET               Si                               NO
    */
    
    std::unique_ptr<Unit> tropa2;
    std::unique_ptr<Unit> tropa3;
}