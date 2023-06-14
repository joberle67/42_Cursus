#include "Convert.hpp"

Convert::Convert(void)
{
}

Convert::Convert(const Convert &src)
{
    (void)src;
}

Convert &Convert::operator=(const Convert &src)
{
    (void) src;
    return (*this);
}

Convert::~Convert(void)
{
}
//https://github.com/izenynn/cpp-modules/blob/main/cpp-module-06/ex00/Scalar.cpp
void Convert::convert(const std::string &str)
{
    std::string special[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    std::string _char = "";
    int         _int = 0;
    float       _float = 0;
    double      _double = 0;

    if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
    {
        _char = str[0];
        std::cout << "Char: " << _char << std::endl;
        std::cout << "Int: "  << static_cast<int>(_char[0]) << std::endl;
        std::cout << "Float: " << static_cast<float>(_char[0]) << ".0f" << std::endl;
        std::cout << "Double: " << static_cast<double>(_char[0]) << ".0" << std::endl;   
    }

    _int = std::atoi(str.c_str());
    
    if (str[str.length() - 1]  == 'f')
    {
        _float = std::atof(str.c_str());
        _double = static_cast<double>(_float);
    }
    else
    {
        _double = std::atof(str.c_str());
        _float = static_cast<float>(_double);
    }

    for(int i = 0; i < 6; i++)
    {
        if (str == special[i])
            _char = "Impossible"; break;
    }

    if (_char == "" && std::isprint(_int))
    {
        _char = "";
        _char += static_cast<char>(_int);
        _char += "";
    }
    else if (_char == "")
        _char = "Non displayable";
    
    std::cout << "char: " << _char << std::endl;
    if (_char == "impossible")
        std::cout << "int: impossible" << std::endl;

    else
        std::cout << "int: " << _int << std::endl;
    
    if (_char == "Impossible" && _float == 0)
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        if (_char != "impossible" && _float - static_cast<int>(_float) == 0)
        {
            std::cout << "float: " << _float << ".0f" << std::endl;
            std::cout << "double: " << _double << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << _float << "f" << std::endl;
            std::cout << "double: " << _double <<   std::endl;
        }
    }
}
