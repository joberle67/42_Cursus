#include "Rpn.hpp"

Rpn::Rpn(){}

Rpn::~Rpn(){}

int Rpn::Calcul(std::string str)
{
    int nb;
    int nb2;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue ;
        else if (isdigit(str[i]))
        {
            nb = stoi(std::string(1, str[i]));
            _stack.push(nb);
        }
        else
        {
            nb2 = _stack.top();
            _stack.pop();
            if (_stack.empty())
            {
                std::cout << "Error" << std::endl;
                exit(0);
            }
            nb = _stack.top();
            _stack.pop();
            if (str[i] == '+')
                _stack.push(nb + nb2);
            else if (str[i] == '-')
				_stack.push(nb - nb2);
			else if (str[i] == '/')
				_stack.push(nb / nb2);
			else if (str[i] == '*')
				_stack.push(nb * nb2);
        }
    }
    return (_stack.top());
}

int Rpn::check_error(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (isdigit(str[i]) == false)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '/'
					|| str[i] == '*' || str[i] == ' ')
				continue ;
			else
				return (-1);
        }
    }
    return (0);
}