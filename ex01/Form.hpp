
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form 
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
	public:
		Form(void);
		Form(const Form &src);
		Form(const std::string _name, const int signGrade, const int execGrade);
		Form operator = (const Form &src);
		~Form(void);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const; 
		void				beSigned(const class Bureaucrat);

};

std::ostream& operator << (std::ostream &out, Bureaucrat &src);

#endif
