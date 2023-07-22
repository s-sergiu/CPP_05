
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat operator = (const Bureaucrat &src);
		~Bureaucrat(void);
		const std::string getName(void);
		int	getGrade(void);
		void GradeTooHighException(void);
		void GradeTooLowException(void);
		void incrementGrade(void);
		void decrementGrade(void);

};

std::ostream& operator << (std::ostream &out, Bureaucrat &src);
#endif
