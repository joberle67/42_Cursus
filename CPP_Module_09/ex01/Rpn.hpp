#pragma once

#include <iostream>
#include <string>
#include <stack>

class Rpn
{
    public :
            Rpn();
            Rpn(const Rpn&);
            Rpn &operator=(const Rpn&);
            ~Rpn();

            int Calcul(std::string);
            int check_error(std::string);

    private :
            std::stack<int> _stack;


};
