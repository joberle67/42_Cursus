#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

		Form(void);
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);

	public:
		Form(const Form &src);

		virtual ~Form();

		Form &operator=(const Form &src);
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

		void beSigned(Bureaucrat const &signer);
		virtual void execute(Bureaucrat const &executor)const = 0;
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
};

std::ostream	&operator<<(std::ostream &o, Form *a);
