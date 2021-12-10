#ifndef HUMANB_HPP
#define HUMANB_HPP
#include<iostream>
#include "Weapon.hpp"

class HumanB
{

public:
    HumanB();
    HumanB(std::string name);
    void attack();
    void setWeapon(Weapon& type);

private:
    std::string name;
    Weapon *weapon;
};

#endif