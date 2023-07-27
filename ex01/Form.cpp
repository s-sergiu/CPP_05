
#include "Form.hpp"

Form::Form(void) 
	: name("Form"), grade(150)
{
	std::cout<<"Form <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Form::Form(const Form &src)
{
	grade = src.grade;
}

Form Form::operator = (const Form &src)
{
	this->grade = src.grade;
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
