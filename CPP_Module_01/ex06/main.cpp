#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac == 2)
        harl.complain(av[1]);
    else
        std::cout << "bad number of arguments" << std::endl;
        return (0);
}