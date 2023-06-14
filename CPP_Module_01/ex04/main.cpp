#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{

    if (ac != 4)
    {
        std::cout << "./exec [nom fichier] [s1] [s2]" << std::endl;
        return (1);
    }
    std::string     file = av[1];
    std::string     s1 = av[2];
    std::string     s2 = av[3];
    std::string     str;

    if (s1.empty() || file.empty() || s2.empty())
    {
        std::cout << "Can't do anything with a empty argument" << std::endl;
        return (1);
    }
    std::ifstream   in(file);
    std::ofstream   out(file + ".replace");
    
    while (in >> str)
    {
        if (str != s1)
            out << str << ' ';
        else
            out << s2 << ' ';
    }
    return (0);
}