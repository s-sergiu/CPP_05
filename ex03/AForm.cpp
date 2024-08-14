
#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	out<<"AForm <"<<src.getName()<<">!";
	out<<std::endl;
	return (out);
}
