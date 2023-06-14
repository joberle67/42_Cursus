#include "Zombie.hpp"

int main(void)
{
    Zombie *a = zombiehorde(5, "charlie");

    int i = 0;

    while (i < 5)
    {
        a[i].announce();
        i++;
    }

    delete [] a;
    return (0);
}