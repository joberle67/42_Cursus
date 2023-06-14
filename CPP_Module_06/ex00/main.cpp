#include "Convert.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Convert a;

        a.convert(av[1]);
        
    }
    else
        std::cout << "Bad number arguments" << std::endl;
    return (0);
}
