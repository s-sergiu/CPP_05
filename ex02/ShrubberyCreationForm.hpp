
#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm(const std::string _name, const int signGrade, const int execGrade);
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm operator = (const ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);
		void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream &out, AForm &src);

#endif
