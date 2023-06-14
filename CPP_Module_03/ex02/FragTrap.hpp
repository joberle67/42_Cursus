#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
    public :
            FragTrap(void);
            FragTrap(std::string name);
            FragTrap(const FragTrap &tmp);
            FragTrap &operator=(const FragTrap &tmp);
            ~FragTrap(void);

            void highFivesGuys(void);

    private :
};

#endif