
#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
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

class AForm::GradeTooLowException : public std::exception
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
	std::cout<<"AForm <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

AForm::AForm(const AForm &src)
	: gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
	this->isSigned = src.getSign();
}

/*
AForm AForm::operator = (const AForm &src)
{
	this->isSigned = src.getSign();
	return *this;
}
*/

AForm::~AForm(void)
{
	std::cout<<"AForm <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

std::ostream& operator << (std::ostream &out, AForm &src)
{
	out<<"AForm <"<<src.getName();
	if (src.getSign() == 1) 
		out<<"> is signed by "<<src.getSigner()<<".";
	else
		out<<"> is not signed.";
	out<<std::endl;
	return (out);
}

void AForm::beSigned(class Bureaucrat &src)
{
	if (src.getGrade() <= gradeSign)
	{
		this->isSigned = true;
		signer = &src;
		std::cout<<"Form signed by "<<src.getName()<<std::endl;
	}
	else
	{
		src.setReason("Grade too Low!\e[0m");
		throw(GradeTooLowException(name, "\e[31m:beSigned"));
	}
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

const std::string AForm::getSigner(void) const
{
	return (this->signer->getName());
}
