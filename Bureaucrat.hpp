
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define HIGHEST 1
#define LOWEST 150

class myException : public std::exception
{
	private:
		std::string	message;
	public:
		myException(std::string &msg) {
			message += msg;
		}
		virtual const char* what() {
			return (this->message).c_str();
		}
};

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(int _grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat operator = (const Bureaucrat &src);
		~Bureaucrat(void);
		const std::string getName(void);
		int	getGrade(void);
		void GradeTooHighException(void);
		void GradeTooLowException(void);
		void incrementGrade(void);
		void decrementGrade(void);

};

std::ostream& operator << (std::ostream &out, Bureaucrat &src);
#endif
