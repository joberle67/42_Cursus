#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <climits>

class Convert
{
    public:
            Convert(void);
            Convert(const Convert &src);
            Convert &operator=(const Convert &src);
            ~Convert();

            void convert(const std::string &str);
    private:
};

#endif