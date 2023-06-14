#include "Zombie.hpp"

Zombie *zombiehorde(int n, std::string name)
{
    int i = 0;
    Zombie *horde = new Zombie[n];
    while (i < n)
    {
        horde[i].set_name(name);
        i++;
    }
    return (horde);
}