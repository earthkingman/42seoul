#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>

class Zombie
{
private:
    std::string name;

public:
    Zombie(void);
    Zombie(std::string name);
    void SetmName(std::string name);
    void announce(void);
    ~Zombie(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
