#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack()
{
    std::cout << name << "attacks with his ";
    if (weapon != NULL)
        std::cout << weapon->getType() << std::endl;
    else
        std::cout << "bare body\n";
}

void HumanB::setWeapon(Weapon& type)
{
    weapon = &type;
}