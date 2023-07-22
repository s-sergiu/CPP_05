
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	grade = 0;
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
	grade++;
}

void Bureaucrat::decrementGrade(void)
{
	grade--;
}

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getGrade()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}
