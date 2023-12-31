#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define HIGHEST 1
#define LOWEST 150

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string _name);
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat operator = (const Bureaucrat &src);
		~Bureaucrat();
		const std::string getName(void);
		int	getGrade(void);
		void incrementGrade(void);
		void decrementGrade(void);
		class GradeTooHighException;
		class GradeTooLowException;

};

std::ostream& operator << (std::ostream &out, Bureaucrat &src);
#endif
