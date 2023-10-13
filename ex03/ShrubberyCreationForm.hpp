
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
		ShrubberyCreationForm(const std::string _name, const int signGrade, const int execGrade);
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm operator = (const ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream &out, AForm &src);

#endif
