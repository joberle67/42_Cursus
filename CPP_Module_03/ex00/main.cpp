#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("daniel");
    a.setAttackDamage(10);
    a.attack("jose");
    ClapTrap b;
    b.setName("jose");
    b.takeDamage(a.getAttackDamage());
    std::cout << b << std::endl;
}