
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define HIGHEST 1
#define LOWEST 150

class Form 
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
	public:
		Form(void);
		Form(const Form &);
		Form(const std::string, const int, const int);
		Form operator = (const Form &);
		~Form(void);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const; 
		class				GradeTooLowException;
		class				GradeTooHighException;
		void				beSigned(const Bureaucrat &);

};

std::ostream& operator << (std::ostream &, Form &);

#endif
