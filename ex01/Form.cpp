
#include "Form.hpp"

// Exception class
// ------------------------------------------------------------------------

class Form::GradeTooHighException : public std::exception
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

class Form::GradeTooLowException : public std::exception
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

// Constructor class
// ------------------------------------------------------------------------

Form::Form(void) 
	: name("Unnamed Form"), isSigned(false),
	  gradeSign(100), gradeExec(100)
{
	std::cout<<"\e[42m\e[30m";
	std::cout<<"Form < \e[106m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[42m\e[30m";
	std::cout<<"> initialized successfully!";
	std::cout<<" -- with required sign grade (rank): ";
	std::cout<<"\e[106m"<<this->getSignGrade();
	std::cout<<"\e[42m\e[30m";
	std::cout<<"!"<<std::endl;
	std::cout<<"\e[0m";
}

Form::Form(const std::string _name, const int signGrade, const int execGrade) 
	: name(_name), isSigned(false), gradeSign(signGrade), 
	  gradeExec(execGrade)
{
	if (this->gradeSign < HIGHEST || this->gradeExec < HIGHEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (this->gradeSign > LOWEST || this->gradeSign > LOWEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"\e[42m\e[30m";
	std::cout<<"Form < \e[106m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[42m\e[30m";
	std::cout<<"> initialized successfully!";
	std::cout<<" -- with required sign grade (rank): ";
	std::cout<<"\e[106m"<<this->getSignGrade();
	std::cout<<"\e[42m\e[30m";
	std::cout<<"!"<<std::endl;
	std::cout<<"\e[0m";
}

Form::Form(const Form &src)
	: name("Copied Form"), gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
	this->isSigned = src.getSign();
}

Form Form::operator = (const Form &src)
{
	this->isSigned = src.getSign();
	return *this;
}

Form::~Form(void)
{
	std::cout<<"\e[45m";
	std::cout<<"Form < \e[106m\e[31m"<<this->getName()<<"\e[0m";
	std::cout<<"\e[45m";
	std::cout<<"> destroyed successfully!"<<std::endl;
	std::cout<<"\e[0m";
}

// Class functions 
// ------------------------------------------------------------------------

void Form::beSigned(const class Bureaucrat &src)
{
	if (src.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw(GradeTooLowException(name, "\e[31m:beSigned"));
}

bool Form::getSign(void) const
{
	return (this->isSigned);
}

const std::string Form::getName(void) const
{
	return (this->name);
}

int Form::getSignGrade(void) const
{
	return (this->gradeSign);
}

int Form::getExecGrade(void) const
{
	return (this->gradeExec);
}

// Overloaded operators
// ------------------------------------------------------------------------

std::ostream& operator << (std::ostream &out, Form &src)
{
	out<<"Form <"<<src.getName();
	if (src.getSign() == 1) 
		out<<"> is signed.";
	else
		out<<"> is not signed.";
	out<<std::endl;
	return (out);
}

