#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{


    std::srand(time(NULL));
    int nb = rand() % 3;
    switch (nb)
    {
        case 0:
                std::cout << "Return new A class" << std::endl;
                return (new A);
        case 1:
                std::cout << "Return new B class" << std::endl;
                return (new B);
        case 2:
                std::cout << "Return new C class" << std::endl;
                return (new C);

    }
    std::cout << "Sorry, i can't create a new class" << std::endl;
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A class was identified" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B class was identified" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C class was identified" << std::endl;
    else
        std::cout << "Can't identify the class" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& aux = dynamic_cast<A&>(p); (void)aux;
        std::cout << "A class was identified" << std::endl;
        return ;
    }
    catch (...){};
    try
    {
        B& aux = dynamic_cast<B&>(p); (void)aux;
        std::cout << "B class was identified" << std::endl;
        return ;
    }
    catch (...){};
    try
    {
        C& aux = dynamic_cast<C&>(p); (void)aux;
        std::cout << "C class was identified" << std::endl;
        return ;
    }
    catch (...){};
}

int main(void)
{
    Base *base;

	base = generate();
	identify(base);
	identify(*base); 
}