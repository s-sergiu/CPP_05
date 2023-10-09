
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm 
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
		const Bureaucrat	*signer;
		AForm(void);
	public:
		AForm(const std::string &target);
		AForm(const AForm &src);
		AForm(const std::string _name, const int signGrade, const int execGrade);
		AForm operator = (const AForm &src);
		~AForm(void);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const; 
		virtual void		beSigned(class Bureaucrat &src);
		class				GradeTooLowException;
		class				GradeTooHighException;
		const std::string	getSigner(void) const;


};

std::ostream& operator << (std::ostream &out, AForm &src);

#endif
