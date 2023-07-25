
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Bureaucrat")
{
	grade = 0;
	std::cout<<"Constructor"<<std::endl;
}

Bureaucrat::Bureaucrat(int _grade) : name ("Bureaucrat")
{
	if (_grade > LOWEST)
		throw 101;
	else if (_grade < HIGHEST)
		throw 102;
	grade = _grade;
	std::cout<<"Constructor"<<std::endl;
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
	std::cout<<"Destructor"<<std::endl;
}

const std::string	Bureaucrat::getName(void)
{
	return (name);
}

int Bureaucrat::getGrade(void)
{
	return (grade);
}

void Bureaucrat::GradeTooHighException(void)
{
}

void Bureaucrat::GradeTooLowException(void)
{
}

void Bureaucrat::incrementGrade(void)
{
	grade--;
	if (grade < HIGHEST)
		throw myException("tes");
}

void Bureaucrat::decrementGrade(void)
{
	grade++;
	if (grade > LOWEST)
		throw myException("tes");
}

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}
