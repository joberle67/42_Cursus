#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->Name = "";
    this->Hit_points = 100;
    this->Energy_point = 50;
    this->Attack_damage = 20;
}


ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap name assignement constructor called" << std::endl;
    this->setName(name);
    this->Hit_points = 100;
    this->Energy_point = 50;
    this->Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &tmp)
{
    std::cout << "ScavTrap copy operator called" << std::endl;
    *this = tmp;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &tmp)
{
    this->Name = tmp.Name;
    this->Hit_points = tmp.Hit_points;
    this->Attack_damage = tmp.Attack_damage;
    this->Energy_point = tmp.Energy_point;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Ciao ScavTrap " << this->getName() << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->Name << " enter in Gate keeper mod" << std::endl;
}