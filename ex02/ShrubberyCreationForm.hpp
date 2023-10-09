
#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP


class ShrubberyCreationForm 
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(const std::string _name, const int signGrade, const int execGrade);
		ShrubberyCreationForm operator = (const ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);
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
