#include "Weapon.hpp"

Weapon::Weapon(std::string type) //생성자
{
    this->type = type;
}

const std::string& Weapon::getType() //getter
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}