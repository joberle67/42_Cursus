#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern : public Form
{
    public:
            Intern(void);
            Intern(const Intern &src);
            ~Intern(void);

            Intern &operator=(const Intern &src);

            Form *makeForm(std::string name, std::string target);

    private:
};