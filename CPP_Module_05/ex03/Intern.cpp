#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constuctor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern copy operator called" << std::endl;
    (void)src;
    return (*this);
}

Intern::~Intern(void)
{
 std::cout << "Intern destructor called" << std::endl;
}

Form *makeCreation(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form *makeRobot(std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form *makePresident(std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string name, std::string target)
{
    Form *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeCreation};
    std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    int i = -1;

    while (++i < 3)
    {
        if(name == forms[i])
        {
            std::cout << "Intern creates " << name << " now" << std::endl;
            return (all_forms[i](target));
        }
    }
    std::cout << "Intern can not create a form called " << name << std::endl;
    return (NULL);
}
