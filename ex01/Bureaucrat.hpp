
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define HIGHEST 1
#define LOWEST 150

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string);
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat operator = (const Bureaucrat &);
		~Bureaucrat(void);
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		class				GradeTooHighException;
		class				GradeTooLowException;
		void				signForm(Form &) const;

};

std::ostream& operator << (std::ostream &, Bureaucrat &);

#endif
