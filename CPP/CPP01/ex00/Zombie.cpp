#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " is died" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << "<" << _name << "> "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}