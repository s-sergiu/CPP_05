
#include "Form.hpp"

class Form::GradeTooHighException : public std::exception
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

class Form::GradeTooLowException : public std::exception
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
	std::cout<<"Form <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Form::Form(const Form &src)
	: gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
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

std::ostream& operator << (std::ostream &out, Form &src)
{
	out<<"Form "<<src.getName()<<", has signed: "<<src.getSign();
	out<<"."<<std::endl;
	return (out);
}

void Form::beSigned(const class Bureaucrat &src)
{
	if (src.getGrade() <= gradeSign)
		this->isSigned = true;
	else
		throw(GradeTooLowException(name, ":beSigned"));
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
