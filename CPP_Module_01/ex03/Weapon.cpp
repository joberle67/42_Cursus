#include "Weapon.hpp"

std::string Weapon::getType(void)
{
    const std::string &ref = this->type;
    return (ref);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(void)
{
    
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(void)
{

}