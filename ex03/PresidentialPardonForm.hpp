
#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
		PresidentialPardonForm(const std::string _name, const int signGrade, const int execGrade);
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm operator = (const PresidentialPardonForm &src);
		~PresidentialPardonForm(void);
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream &out, AForm &src);

#endif
