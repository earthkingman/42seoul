#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is died" << std::endl;
}

void Zombie::SetmName(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << "<" << this->name << "> "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}