
#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
		RobotomyRequestForm(const std::string _name, const int signGrade, const int execGrade);
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm operator = (const RobotomyRequestForm &src);
		~RobotomyRequestForm(void);
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream &out, AForm &src);

#endif
