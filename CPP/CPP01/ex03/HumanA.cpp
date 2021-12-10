#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string s, Weapon& w) : name(s), weapon(w) {}

// HumanA::HumanA(std::string name, Weapon &w)
// {
//     this->name = name;
//     weapon = w;
// }

void HumanA::setWeapon(Weapon& type)
{
    weapon = type;
}