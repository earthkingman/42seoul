#ifndef HUMANA_HPP
#define HUMANA_HPP
#include<iostream>
#include "Weapon.hpp"

class HumanA
{
public:
    HumanA();
    HumanA(std::string name, Weapon &w);
    void attack();
    void setWeapon(Weapon& type);

private:
    std::string name;
    Weapon &weapon;
};

#endif