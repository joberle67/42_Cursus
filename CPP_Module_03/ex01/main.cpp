#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap a("daniel");
    a.setAttackDamage(10);
    a.attack("jose");
    ClapTrap b;
    ScavTrap c("Mamadou");
    ScavTrap p = c;
    std::cout << p << std::endl;
    b.setName("jose");
    b.takeDamage(a.getAttackDamage());
    p.guardGate();
    std::cout << p.getName() << std::endl;
}