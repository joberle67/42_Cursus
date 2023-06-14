#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
            Zombie(void);
            void set_name(std::string name);
            void announce(void);
            ~Zombie();

    private:
            std::string name;
};

Zombie *zombiehorde(int n, std::string name);

# endif