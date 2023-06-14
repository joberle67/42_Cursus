#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    public :
            Bureaucrat(void);
            Bureaucrat(std::string name, int grade);
            Bureaucrat(const Bureaucrat &src);
            Bureaucrat &operator=(const Bureaucrat &src);
            ~Bureaucrat(void);
            
            void incrementGrade(void);
            void decrementGrade(void);

            void setGrade(int grade);

            std::string getName(void);
            int getGrade(void);

            class GradeTooLowException : public std::exception
            {
                public : 
                virtual const char *what() const throw();
            };

            class GradeTooHighException : public std::exception
            {
                public : 
                virtual const char *what() const throw();
            };

    private :
            const std::string name;
            int         grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &src);

#endif