
#include "Bureaucrat.hpp"

// Exception class
// ------------------------------------------------------------------------

class Bureaucrat::GradeTooHighException : public std::exception
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

class Bureaucrat::GradeTooLowException : public std::exception
{
	private:
		std::string _msg;
	public:
		GradeTooLowException(std::string _name, std::string msg) throw()
			: _msg(msg.insert(0, _name)) {	
		_msg.insert(0, "\e[4m"); 
		_msg.append(" \e[96m-> Grade too low!\e[0m");
		}
		~GradeTooLowException() throw() {}
		const char* what() const throw() {
			return _msg.c_str();
		}
};

// Constructor class
// ------------------------------------------------------------------------

Bureaucrat::Bureaucrat(void) 
	: name("\e[105m Unnamed Bureaucrat \e[0m"), grade(150)
{
	std::cout<<"\e[47m\e[30m";
	std::cout<<"Bureaucrat < \e[106m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[47m\e[30m";
	std::cout<<"> initialized successfully!";
	std::cout<<" -- with grade (rank): \e[106m"<<this->getGrade();
	std::cout<<"\e[47m\e[30m";
	std::cout<<"!"<<std::endl;
	std::cout<<"\e[0m";
}

Bureaucrat::Bureaucrat(std::string _name) 
	: name(_name), grade(150)
{
	std::cout<<"\e[47m\e[30m";
	std::cout<<"Bureaucrat < \e[106m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[47m\e[30m";
	std::cout<<"> initialized successfully!";
	std::cout<<" -- with grade (rank): \e[106m"<<this->getGrade();
	std::cout<<"\e[47m\e[30m";
	std::cout<<"!"<<std::endl;
	std::cout<<"\e[0m";
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) 
	: name(_name), grade(_grade)
{
	if (_grade < HIGHEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (_grade > LOWEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"\e[47m\e[30m";
	std::cout<<"Bureaucrat < \e[106m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[47m\e[30m";
	std::cout<<"> initialized successfully!";
	std::cout<<" -- with grade (rank): \e[106m"<<this->getGrade();
	std::cout<<"\e[47m\e[30m";
	std::cout<<"!"<<std::endl;
	std::cout<<"\e[0m";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: name("Copied Bureaucrat")
{
	this->grade = src.getGrade();
}

Bureaucrat Bureaucrat::operator = (const Bureaucrat &src)
{
	this->grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout<<"\e[101m";
	std::cout<<"Bureaucrat < \e[106m\e[31m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[101m";
	std::cout<<"> destroyed successfully!"<<std::endl;
	std::cout<<"\e[0m";
}

// Class functions 
// ------------------------------------------------------------------------

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
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
		throw GradeTooLowException(name, ":Decrementing");
	else
		this->grade++;
}

// Overloaded operators
// ------------------------------------------------------------------------

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}
