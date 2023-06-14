#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat test("valentin", 150);
    Bureaucrat b;
    
    b = test;

    try{
        b.incrementGrade();
    }
    
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try{
        b.incrementGrade();
    }

     catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << test;
    
}