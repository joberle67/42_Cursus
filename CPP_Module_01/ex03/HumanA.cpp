#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA (void)
{
    std::cout << "R.I.P " << this->name << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacked with " << this->weapon->getType() << '\n';
}

