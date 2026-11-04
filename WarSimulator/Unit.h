#pragma once
#include <string>

class Unit
{
    
    /*
protected:
    // Atributs protegits: accessibles des de les classes filles
    std::string name;
    int heal;
    int armor;
    int dmg;

    float attackSpeed;
    float attackProgress; // Acumula la velocitat d'atac entre rondes

public:
    
    /*APUNTSSSS
     static int numeroDeTropas;
     
     desptes del switch
     
     numDeTropas +=1;
     
          
     */
    
    /*
    // Constructor: inicialitza les característiques de la unitat
    Unit(const std::string& name, int heal, int armor,
         int dmg, float attackSpeed);

    // Destructor virtual: permet destruir correctament les classes filles
    virtual ~Unit();

    // Getters: permeten consultar els atributs
    std::string getName() const;
    int getHeal() const;
    int getArmor() const;
    bool isAlive() const;

    // Rep el dany d'un atac
    void getDmg(int incomingDamage);

    // Calcula quants atacs pot fer durant una ronda
    int getAttacksThisRound();

    // Cada tipus d'unitat implementarà el seu propi càlcul de dany
    virtual int calculateDamage() const = 0;
    
    */
    
    public:
    
    enum UnitType {Soldier, Infantery, Sniper};
    
    Unit(UnitType unitType, int _quantity)
    {
        switch (unitType)
        {
            case 0:
            
            break;
        }
        
        
        
        
        
    }
    
};
