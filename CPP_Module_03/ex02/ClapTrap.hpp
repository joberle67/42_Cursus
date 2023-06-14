#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public :
            ClapTrap(void);
            ClapTrap(std::string name);
            ClapTrap(const ClapTrap &src);
            ClapTrap &operator=(const ClapTrap &src);
            ~ClapTrap(void);

            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int ammount);

            std::string getName(void);
            unsigned int getHit(void);
            unsigned int getEnergy(void);
            unsigned int getAttackDamage(void);
        

            void setName(std::string name);
            void setHit(unsigned int nb);
            void setEnergy(unsigned int nb);
            void setAttackDamage(unsigned int nb);

    protected :
            std::string Name;
            unsigned int Hit_points;
            unsigned int Energy_point;
            unsigned int Attack_damage;
};

std::ostream &operator<<(std::ostream &o, ClapTrap &tmp);


# endif