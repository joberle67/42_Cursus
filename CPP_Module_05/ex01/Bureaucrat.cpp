
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("")
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    std::cout << "Bureaucrat assignement constructor called" << std::endl;
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    std::cout << "Bureaucrat copy operator called" << std::endl;
    this->grade = src.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

int Bureaucrat::getGrade(void)
{
    return(this->grade);
}


std::string Bureaucrat::getName(void)
{
    return (this->name);
}

void Bureaucrat::incrementGrade(void)
{
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade--;
}

void Bureaucrat::decrementGrade(void)
{

        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (o);
}

void Bureaucrat::setGrade(int grade)
{
    
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

void Bureaucrat::signForm(Form &src)
{
    if (src.getSign() == true)
        std::cout << this->name << " signed " << src.getName() << std::endl;
    else
        std::cout << this->name << " couldn't signed " << src.getName() << " because he don't have the good grade" << std::endl;

}
