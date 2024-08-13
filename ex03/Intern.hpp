
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Intern
{
	private:
	public:
		Intern(void);
		Intern(std::string);
		Intern(std::string, int);
		Intern(const Bureaucrat &);
		Bureaucrat operator = (const Bureaucrat &);
		~Intern(void);
		AForm*	makeForm(std::string, std::string) const;
};

std::ostream& operator << (std::ostream &, Intern &);

#endif
