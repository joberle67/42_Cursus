#include "Harl.hpp"


Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void Harl::complain(std::string level)
{
    int i = 0;
    int index;
    std::string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    void (Harl::*fct[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    while (i < 4)
    {
        if (msg[i] == level)
        {
            std::cout <<"[ " << level <<" ]" << std::endl;
            index = i;
            break;
        }
        i++;
    }
    if (i == 4)
    {
        std::cout << "This command doesn't exist" << std::endl;
        return ;
    }

    i = index;
    switch(index)
    {
        case(0) :
                while (i < 4)
                {
                    (this->*(fct[i]))();
                    i++;
                }
                
        case(1) :
                while (i < 4)
                {
                    (this->*(fct[i]))();
                    i++;
                }

        case(2) :
                while (i < 4)
                {
                    (this->*(fct[i]))();
                    i++;
                }
        
        case(3) :
                while (i < 4)
                {
                    (this->*(fct[i]))();
                    i++;
                }
    }
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my" <<
    "7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" <<
    "enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming" << 
    "for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}