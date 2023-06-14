#include <iostream>
#include <stdio.h>

int main(int ac, char **av)
{
    int a;
    int i;

    a = 1;
    if (ac == 1)
    {
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    while (av[a])
    {
        i = -1;
        while (av[a][++i])
            putchar(toupper(av[a][i]));
        a++;
    }
    std :: cout << "\n";
}