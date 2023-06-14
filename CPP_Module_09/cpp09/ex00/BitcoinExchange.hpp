#pragma once

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <fstream>

class BitcoinExchange
{
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange &operator=(const BitcoinExchange&);
        ~BitcoinExchange();
        
        void DataBase(std::string);
        void Input(std::string);
        void Search();

        float SearchDate(std::string);
        int CheckDate(std::string);
    
    private :
            std::map<std::string, float> _data;
            int _check;
};