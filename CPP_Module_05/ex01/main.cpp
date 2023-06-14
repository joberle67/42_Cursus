#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat test("valentin", 150);
    Bureaucrat b("luc", 150);
    Form c("lucas", 140 , 150);

    try{
        b.incrementGrade();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    try{
        c.Besigned(b);
    }

     catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    b.signForm(c);

    try{
        b.decrementGrade();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    try{
        b.decrementGrade();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    try{
        b.decrementGrade();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    std::cout << b;
    std::cout << c;
}