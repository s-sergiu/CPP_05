
#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>

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
		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(std::string _name, std::string msg) throw()
					: _msg(msg.insert(0, _name)) {
				_msg.insert(0, "\e[4m"); 
				_msg.append(" \e[91m -> Grade too high!\e[0m"); 
				}
				~GradeTooHighException() throw() {}
				const char* what() const throw() {
					return _msg.c_str();
				}
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(std::string _name, std::string msg) throw()
					: _msg(msg.insert(0, _name)) {
				_msg.insert(0, "\e[4m"); 
				_msg.append(" \e[91m -> Grade too low!\e[0m"); 
				}
				~GradeTooLowException() throw() {}
				const char* what() const throw() {
					return _msg.c_str();
				}
		};
		AForm(void);
		AForm(const std::string &);
		AForm(const AForm &);
		AForm(const std::string , const int , const int);
		~AForm(void);
		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const; 
		void				beSigned(const Bureaucrat *);
		virtual void		execute(const Bureaucrat &) const = 0;
};

std::ostream& operator << (std::ostream &, AForm &);

#endif
