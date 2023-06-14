#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->Name = "";
    this->Hit_points = 100;
    this->Energy_point = 100;
    this->Attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap name assignement constructor called" << std::endl;
    this->setName(name);
    this->Hit_points = 100;
    this->Energy_point = 100;
    this->Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &tmp)
{
    std::cout << "FragTrap copy operator called" << std::endl;
    *this = tmp;
}

FragTrap &FragTrap::operator=(const FragTrap &tmp)
{
    this->Name = tmp.Name;
    this->Hit_points = tmp.Hit_points;
    this->Attack_damage = tmp.Attack_damage;
    this->Energy_point = tmp.Energy_point;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "Ciao FragTrap " << this->Name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->Name << " want a High Fives" << std::endl;
}