
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
		AForm operator = (const AForm &);
	public:
		AForm(void);
		AForm(const std::string &);
		AForm(const AForm &);
		AForm(const std::string , const int , const int);
		~AForm(void);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const; 
		class				GradeTooLowException;
		class				GradeTooHighException;
		void				beSigned(void);
		virtual void		execute(const Bureaucrat &) const = 0;
};

std::ostream& operator << (std::ostream &, AForm &);

#endif
