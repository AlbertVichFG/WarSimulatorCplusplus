#include "Battle.h"

#include <iostream>

// Constructor: rep els dos exercits i inicialitza el generador aleatori
Battle::Battle(Army& armyA, Army& armyB)
    : armyA(armyA),
      armyB(armyB),
      generator(std::random_device{}())
{
}

// Selecciona una unitat enemiga que continuï viva
Unit* Battle::selectRandomTarget(Army& targetArmy)
{
    std::vector<Unit*> aliveUnits;

    // Guardem nomes les unitats que continuen vives
    for (Unit* unit : targetArmy.getUnits())
    {
        if (unit->isAlive())
        {
            aliveUnits.push_back(unit);
        }
    }

    // Si no queden enemics vius, retornem un punter buit
    if (aliveUnits.empty())
    {
        return nullptr;
    }

    // Seleccionem aleatoriament una unitat del vector
    std::uniform_int_distribution<int> distribution(
        0, static_cast<int>(aliveUnits.size()) - 1
    );

    return aliveUnits[distribution(generator)];
}

// Calcula el dany amb una variacio aleatoria del -20% al +20%
int Battle::calculateRandomDamage(int baseDamage)
{
    std::uniform_int_distribution<int> distribution(-20, 20);

    int variation = distribution(generator);

    // Apliquem el percentatge aleatori al dany base
    return baseDamage * (100 + variation) / 100;
}

// Gestiona els atacs d'un exercit contra l'altre
void Battle::attackArmy(Army& attacker, Army& defender)
{
    for (Unit* unit : attacker.getUnits())
    {
        // Les unitats mortes no poden atacar
        if (!unit->isAlive())
            continue;

        // Calculem quants atacs pot fer aquesta unitat
        int attacks = unit->getAttacksThisRound();

        for (int i = 0; i < attacks; i++)
        {
            // Si no queden enemics vius, acabem els atacs
            if (!defender.hasLivingUnits())
                return;

            // Seleccionem un enemic aleatori
            Unit* target = selectRandomTarget(defender);

            if (target == nullptr)
                return;

            // Calculem el dany amb la variacio aleatoria
            int damage = calculateRandomDamage(unit->calculateDamage());

            // Apliquem el dany tenint en compte el blindatge de l'enemic
            target->getDmg(damage);
        }
    }
}

// Inicia la simulacio de la guerra
void Battle::start()
{
    // Distribució aleatòria: 0 = A comença, 1 = B comença
    std::uniform_int_distribution<int> firstAttacker(0, 1);

    // El combat continua mentre els dos exèrcits tinguin unitats vives
    while (armyA.hasLivingUnits() && armyB.hasLivingUnits())
    {
        // Decidim aleatòriament qui ataca primer aquesta ronda
        int first = firstAttacker(generator);

        if (first == 0)
        {
            // Primer ataca A
            attackArmy(armyA, armyB);

            // Després contraataca B si encara té unitats
            if (armyB.hasLivingUnits())
                attackArmy(armyB, armyA);
        }
        else
        {
            // Primer ataca B
            attackArmy(armyB, armyA);

            // Després contraataca A si encara té unitats
            if (armyA.hasLivingUnits())
                attackArmy(armyA, armyB);
        }
    }

    // Mostrem el resultat final
    showResults();
}

// Mostra el guanyador i les baixes
void Battle::showResults() const
{
    std::cout << "\n===== BATTLE RESULTS =====\n";

    // Determinem quin exercit ha guanyat
    if (armyA.hasLivingUnits() && !armyB.hasLivingUnits())
    {
        std::cout << "WINNER: " << armyA.getName() << std::endl;
    }
    else if (armyB.hasLivingUnits() && !armyA.hasLivingUnits())
    {
        std::cout << "WINNER: " << armyB.getName() << std::endl;
    }
    else
    {
        std::cout << "DRAW: No army has survived." << std::endl;
    }

    // Resultats de l'exercit A
    std::cout << "\n" << armyA.getName() << std::endl;
    std::cout << "Survivors: " << armyA.getAliveCount() << std::endl;
    std::cout << "Deaths: " << armyA.getCasualtiesCount() << std::endl;

    // Resultats de l'exercit B
    std::cout << "\n" << armyB.getName() << std::endl;
    std::cout << "Survivors: " << armyB.getAliveCount() << std::endl;
    std::cout << "Deaths: " << armyB.getCasualtiesCount() << std::endl;

    std::cout << "\n=========================\n";
}