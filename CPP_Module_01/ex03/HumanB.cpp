#include "HumanB.hpp"

HumanB::HumanB (std::string name)
{
	this->name = name;
}

HumanB::~HumanB ()
{
    std::cout << "R.I.P " << this->name << std::endl; 
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacked with " << this->weapon->getType() << '\n';
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}