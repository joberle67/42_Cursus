#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
        typedef void (Harl::*function)(void);
    public:
                Harl(void);
                void complain(std::string level);
                ~Harl(void);

    private:
                void debug(void);
                void info(void);
                void warning(void);
                void error(void);
};

#endif