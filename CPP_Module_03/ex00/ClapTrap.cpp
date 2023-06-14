#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->Name = "";
    this->Hit_points = 10;
    this->Energy_point = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Name assignement constructor called" << std::endl;
    this->Name = name;
    this->Hit_points = 10;
    this->Energy_point = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "ClapTrap copy operator called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    this->Name = src.Name;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Ciao " << this->Name << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->Energy_point > 0)
    {
        std::cout << "ClapTrap " << this->Name << " attacks "
            << target << ", causing " << this->Attack_damage << " points of damage" << std::endl;
        this->Energy_point -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->Name << " take " << amount << " damage" << std::endl;
    this->Hit_points -= amount;
    if (this->Hit_points <= 0)
        std::cout << this->Name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_point > 0)
    {
        std::cout << this->Name << " regain " << amount << " hit points" << std::endl;
        this->Energy_point += amount;
        this->Energy_point -= 1;
    }
}

void ClapTrap::setName(std::string name)
{
    std::cout << "Have set name" << std::endl;
    this->Name = name;
}

void ClapTrap::setAttackDamage(unsigned int nb)
{
    std::cout << "Have set attack damage" << std::endl;
    this->Attack_damage = nb;
}

void ClapTrap::setEnergy(unsigned int nb)
{
    std::cout << "Have set energy" << std::endl;
    this->Energy_point = nb;
}

void ClapTrap::setHit(unsigned int nb)
{
    std::cout << "Have set hit" << std::endl;
    this->Hit_points = nb;
}

std::string ClapTrap::getName(void)
{
    return (this->Name);
}

unsigned int ClapTrap::getHit(void)
{
    return (this->Hit_points);
}

unsigned int ClapTrap::getEnergy(void)
{
    return (this->Energy_point);
}

unsigned int ClapTrap::getAttackDamage(void)
{
    return (this->Attack_damage);
}

std::ostream &operator<<(std::ostream &o, ClapTrap &tmp)
{
        o << "Name : " << tmp.getName() << "\nHit points : " << tmp.getHit()
        << "\nEnergy : " << tmp.getEnergy() << "\nAttacks damage : " << tmp.getAttackDamage();
        return (o);
}

