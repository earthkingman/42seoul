#include "Zombie.hpp"

int main(void)
{
    Zombie zombie1("zombie1");
    zombie1.announce();

    Zombie *zombie2 = newZombie("zombie2");
    zombie2->announce();
    delete zombie2;

    randomChump("zombie3");
    return 0;
}