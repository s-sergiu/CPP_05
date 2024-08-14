
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &);
		Intern operator = (const Intern &);
		~Intern(void);
		void makeForm(const std::string &,const std::string &) const;
};

#endif
