
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	protected:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
		const Bureaucrat	*signer;
	public:
		AForm(void);
		AForm(const std::string &target);
		AForm(const AForm &src);
		AForm(const std::string _name, const int signGrade, const int execGrade);
		//AForm operator = (const AForm &src);
		~AForm(void);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const; 
		virtual void		beSigned(class Bureaucrat &src);
		class				GradeTooLowException;
		class				GradeTooHighException;
		const std::string	getSigner(void) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;


};

std::ostream& operator << (std::ostream &out, AForm &src);

#endif
