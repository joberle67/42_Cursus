#include "Form.hpp"
Form::Form(void) : name("Default"), grade_sign(150), grad_exec(150)
{
    std::cout << "Form default constructor called" << std::endl;
    this->is_sign = false;
}

Form::Form(std::string name, int sign, int exec) : name(name), grade_sign(sign), grad_exec(exec)
{
    std::cout << "Form assignement constructor called" << std::endl;
}

Form::Form(const Form &src) : name(src.name), grade_sign(src.grade_sign), grad_exec(src.grad_exec)
{
    std::cout << "Form copy constructor called" << std::endl;
    *this = src;
}

Form &Form::operator=(const Form &src)
{
    (void)src;
    return (*this);
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}


void Form::Besigned(Bureaucrat src)
{
    if (src.getGrade() <= this->grade_sign)
        this->is_sign = true;
    else
        throw Form::GradeTooLowException();
    return ;
}

std::string Form::getName(void)
{
    return (this->name);
}

bool Form::getSign(void)
{
    return (is_sign);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low for sign");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high for sign");
}

int Form::getGradeExec(void)
{
    return (this->grad_exec);
}

int Form::getGradeSign(void)
{
    return (grade_sign);
}

std::ostream &operator<<(std::ostream &o, Form &src)
{
    o << "required grade for sign " << ": " << src.getGradeSign() << "\n" << "required grade for execute : " << src.getGradeExec() << "\n" << "the Form is sign ? : " << src.getSign() << std::endl;
    return (o);
}