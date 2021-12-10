#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon *w)
{
    name = name;
    weapon = w;
}

void HumanA::setWeapon(Weapon& type)
{
    weapon = &type;
}