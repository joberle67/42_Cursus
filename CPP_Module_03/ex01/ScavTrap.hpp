#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
            ScavTrap(void);
            ScavTrap(std::string name);
            ScavTrap(const ScavTrap &tmp);
            ScavTrap &operator=(const ScavTrap &tmp);
            ~ScavTrap(void);

            void guardGate(void);

    private :
};

#endif