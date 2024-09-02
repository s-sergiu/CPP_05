
#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
		ShrubberyCreationForm(const std::string, const int , const int );
	public:
		ShrubberyCreationForm(const std::string &);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm operator = (const ShrubberyCreationForm &);
		~ShrubberyCreationForm(void);
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream &, AForm &);

#endif
