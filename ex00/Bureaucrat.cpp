
#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	private:
		std::string _msg;
		std::string _name;
		std::string _error;
	public:
		GradeTooHighException(std::string _name, std::string msg) 
			: _msg(msg.insert(0, _name)), 
			_name(_name), 
			_error("->Grade too Low!") { _msg.append(_error); }
		~GradeTooHighException() throw() {}
		const char* what() const throw() {
			return _msg.c_str();
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	private:
		std::string _msg;
		std::string _name;
		std::string _error;
	public:
		GradeTooLowException(std::string _name, std::string msg) 
			: _msg(msg.insert(0, _name)), 
			_name(_name), 
			_error("->Grade too Low!") { _msg.append(_error); }
		~GradeTooLowException() throw() {}
		const char* what() const throw() {
			return _msg.c_str();
		}
};

Bureaucrat::Bureaucrat(void) 
	: name("Unnamed Bureaucrat"), grade(150)
{
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string _name) 
	: name(_name), grade(150)
{
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) 
	: name(_name), grade(_grade)
{
	if (_grade > LOWEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (_grade < HIGHEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: name("Copied Bureaucrat")
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
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

const std::string	Bureaucrat::getName(void)
{
	return (this->name);
}

int Bureaucrat::getGrade(void)
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	if ((grade - 1) < HIGHEST)
		throw GradeTooHighException(name, ":Incrementing");
	else
		this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if ((grade + 1) > LOWEST)
		throw GradeTooLowException(name, ":Incrementing");
	else
		this->grade++;
}

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}
