
#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	private:
		std::string msg;
	public:
		GradeTooHighException() : msg("Error: Grade too high...") {}
		GradeTooHighException(std::string msg) : msg(msg) {}
		~GradeTooHighException() throw() {}
		const char* what() const throw() {
			return msg.c_str();
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	private:
		std::string msg;
	public:
		GradeTooLowException() : msg("Error: Grade too low...") {}
		GradeTooLowException(std::string msg) : msg(msg) {}
		~GradeTooLowException() throw() {}
		const char* what() const throw() {
			return msg.c_str();
		}
};

Bureaucrat::Bureaucrat(void) : name("Bureaucrat")
{
	grade = 150;
	std::cout<<"Bureaucrat initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (_grade > LOWEST)
		throw GradeTooHighException();
	else if (_grade < HIGHEST)
		throw GradeTooLowException();
	grade = _grade;
	std::cout<<"Bureaucrat initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	grade = src.grade;
}

Bureaucrat Bureaucrat::operator = (const Bureaucrat &src)
{
	this->grade = src.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout<<"Bureaucrat destroyed successfully!"<<std::endl;
}

const std::string	Bureaucrat::getName(void)
{
	return (name);
}

int Bureaucrat::getGrade(void)
{
	return (grade);
}

void Bureaucrat::incrementGrade(void)
{
	if ((grade - 1) < HIGHEST)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if ((grade + 1) > LOWEST)
		throw GradeTooLowException();
	else
		grade++;
}

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}
