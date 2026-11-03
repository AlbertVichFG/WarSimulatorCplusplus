
#include <random>

#include "Army.h"

class Battle
{
private:
    Army& armyA;
    Army& armyB;

    // Generador de nombres aleatoris
    std::mt19937 generator;

    // Selecciona un enemic viu aleatori
    Unit* selectRandomTarget(Army& targetArmy);

    // Calcula el dany amb una variació aleatòria
    int calculateRandomDamage(int baseDamage);

    // Gestiona els atacs d'un exèrcit
    void attackArmy(Army& attacker, Army& defender);

    // Mostra els resultats finals
    void showResults() const;

public:
    Battle(Army& armyA, Army& armyB);

    // Inicia la guerra
    void start();
};

