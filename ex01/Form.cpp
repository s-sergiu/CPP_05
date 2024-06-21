
#include "Form.hpp"

// Exception class
// ------------------------------------------------------------------------

class Form::GradeTooHighException : public std::exception
{
	private:
		std::string _msg;
	public:
		GradeTooHighException(std::string _name, std::string msg) 
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
		GradeTooLowException(std::string _name, std::string msg) 
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
	: name("<Form>"), isSigned(false),
	  gradeSign(100), gradeExec(100)
{
	std::cout<<"Form <"<<name;
	std::cout<<"> initialized successfully!";
	std::cout<<" with required sign grade (";
	std::cout<<this->getSignGrade()<<")"<<std::endl;
}

Form::Form(const std::string _name, const int signGrade, const int execGrade) 
	: name(_name), isSigned(false), gradeSign(signGrade), 
	  gradeExec(execGrade)
{
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"Form <"<<name;
	std::cout<<"> initialized successfully!";
	std::cout<<" with required sign grade (";
	std::cout<<this->getSignGrade()<<")"<<std::endl;
}

Form::Form(const Form &src)
	: gradeSign(src.gradeSign), gradeExec(src.gradeExec)
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
	std::cout<<"Form <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

// Class functions 
// ------------------------------------------------------------------------

void Form::beSigned(const class Bureaucrat &src)
{
	if (src.getGrade() <= gradeSign)
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

