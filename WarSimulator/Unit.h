#pragma once
#include <string>

class Unit
{
public:
    std :: string name;
    int heal;
    int armor;
    int dmg;
    float atackSpeed;
    
    Unit(std::string name, int heal, int armor, float atackSpeed);
    
    virtual ~Unit();
    
    std::string getName();
    int getHeal();
    int getArmor();
    bool isAlive();
    
    void getDmg( int _damage);
    
    virtual int calculateDamage() = 0;
    
};
