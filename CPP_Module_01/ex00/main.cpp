#include "Zombie.hpp"

int     main(void)
{
    Zombie *a = newZombie("Eden");

    randomChump("Hazard");
    delete a;
    return (0);
}