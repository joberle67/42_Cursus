#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    BitcoinExchange btc;

    btc.DataBase("data.csv");
    btc.Input(av[1]);
}