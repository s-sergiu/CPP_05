
#include "Form.hpp"

Form::Form(void) 
	: name("<Form>"), isSigned(false),
	  gradeSign(100), gradeExec(100)
{
	std::cout<<"Form <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Form::Form(const std::string _name, const int signGrade, const int execGrade) 
	: name(_name),
	  isSigned(false), gradeSign(signGrade), gradeExec(execGrade)
{
}

Form::Form(const Form &src)
	: gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
}

Form Form::operator = (const Form &src)
{
	this->name = src.getName();
	this->isSigned = src.getSign();
	this->gradeSign = src.getSignGrade();
	this->gradeExec = src.getExecGrade();

	return *this;
}

Form::~Form(void)
{
	std::cout<<"Form <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

std::ostream& operator << (std::ostream &out, Form &src)
{
	out<<"Form "<<src.getName()<<", has signed: "<<src.getSign();
	out<<"."<<std::endl;
	return (out);
}

void Form::beSigned(const class Bureaucrat &src)
{
	if (src.getGrade() > grade_sign)
		this->isSigned = true;
	else
		throw("Grade too low");
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
