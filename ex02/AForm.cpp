
#include "AForm.hpp"

// Exception class
// ------------------------------------------------------------------------

class AForm::GradeTooHighException : public std::exception
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

class AForm::GradeTooLowException : public std::exception
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

AForm::AForm(void) 
	: name("<AForm>"), isSigned(false),
	  gradeSign(100), gradeExec(100)
{
	std::cout<<"AForm <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

AForm::AForm(const std::string _name, const int signGrade, const int execGrade) 
	: name(_name), isSigned(false), gradeSign(signGrade), 
	  gradeExec(execGrade)
{
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"AForm <"<<this->getName();
	std::cout<<"> initialized successfully!"<<std::endl;
}

AForm::AForm(const AForm &src)
	: gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
	this->isSigned = src.getSign();
}

AForm::~AForm(void)
{
	std::cout<<"AForm <"<<this->getName();
	std::cout<<"> destroyed successfully!"<<std::endl;
}

// Class functions 
// ------------------------------------------------------------------------

void AForm::beSigned(const Bureaucrat *src) 
{
	if (src->getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw(GradeTooLowException(name, "\e[31m:beSigned"));
}

bool AForm::getSign(void) const
{
	return (this->isSigned);
}

const std::string AForm::getName(void) const
{
	return (this->name);
}

int AForm::getSignGrade(void) const
{
	return (this->gradeSign);
}

int AForm::getExecGrade(void) const
{
	return (this->gradeExec);
}

// Overloaded operators
// ------------------------------------------------------------------------

std::ostream& operator << (std::ostream &out, AForm &src)
{
	out<<"AForm <"<<src.getName();
	if (src.getSign() == 1) 
		out<<"> is signed."; 
	else
		out<<"> is not signed.";
	out<<std::endl;
	return (out);
}
