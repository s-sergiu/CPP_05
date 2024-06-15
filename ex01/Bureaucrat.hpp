
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
		Bureaucrat(void);
		Bureaucrat(std::string _name);
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat operator = (const Bureaucrat &src);
		~Bureaucrat(void);
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		class				GradeTooHighException;
		class				GradeTooLowException;
		void				signForm(const class Form &_form);

};

std::ostream& operator << (std::ostream &out, Bureaucrat &src);

#endif
