
#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	private:
		std::string _msg;
		std::string _name;
		std::string _error;
	public:
		GradeTooHighException() 
			: _msg(" Error: "), _name("Bureaucrat") {}
		GradeTooHighException(std::string msg) 
			: _msg(msg.insert(0, "Bureaucrat")) {}
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
		GradeTooLowException() 
			: _msg(" Error: "), _name("Bureaucrat") {}
		GradeTooLowException(std::string msg) 
			: _msg(msg.insert(0, "Bureaucrat")) {}
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
	: name("Bureaucrat"), grade(150)
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
		throw GradeTooHighException("Increment: Grade too High!");
	else
		this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if ((grade + 1) > LOWEST)
		throw GradeTooLowException("Decrement: Grade too Low!");
	else
		this->grade++;
}

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}
