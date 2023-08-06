
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
			  _error("->Grade too High!\e[0m") { _msg.append(_error); }
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
			  _error("->Grade too Low!\e[0m") { _msg.append(_error); }
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
	: name(_name), isSigned(false), gradeSign(signGrade), 
	  gradeExec(execGrade)
{
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"Form <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
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

std::ostream& operator << (std::ostream &out, Form &src)
{
	out<<"Form <"<<src.getName();
	if (src.getSign() == 1) 
		out<<"> is signed by "<<src.getSigner()<<".";
	else
		out<<"> is not signed.";
	out<<std::endl;
	return (out);
}

void Form::beSigned(class Bureaucrat &src)
{
	if (src.getGrade() <= gradeSign)
	{
		this->isSigned = true;
		signer = &src;
	}
	else
	{
		src.setReason("Grade too Low!\e[0m");
		throw(GradeTooLowException(name, "\e[31m:beSigned"));
	}
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

const std::string Form::getSigner(void) const
{
	return (this->signer->getName());
}
