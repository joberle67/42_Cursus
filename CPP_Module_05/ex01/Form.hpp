#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public :

            Form(void);
            Form(std::string name, int sign, int exec);
            Form(const Form &src);
            Form &operator=(const Form &src);
            ~Form(void);

            std::string getName(void);
            bool getSign(void);
            int getGradeExec(void);
            int getGradeSign(void);

            void Besigned(Bureaucrat src);

            
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
    private :
            const std::string   name;
            bool                is_sign;
            const int           grade_sign;
            const int           grad_exec;
};

std::ostream &operator<<(std::ostream &o, Form &src);

#endif