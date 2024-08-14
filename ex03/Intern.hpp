
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define SHRUBBERY 0
#define ROBOTOMY 1
#define PRESIDENTIAL 2

#define A "shrubbery creation"
#define B "robotomy request"
#define C "presidential pardon"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &);
		Intern operator = (const Intern &);
		~Intern(void);
		class UnableToInitForm;
		AForm* makeForm(const std::string &,const std::string &) const;
};

#endif
