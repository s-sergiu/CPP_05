
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
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

class Bureaucrat::GradeTooLowException : public std::exception
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

Bureaucrat::Bureaucrat(void) 
	: name("Bureaucrat"), grade(150)
{
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string _name) 
	: name(_name), grade(150)
{
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) 
	: name(_name), grade(_grade)
{
	if (_grade > LOWEST)
		throw GradeTooHighException(_name, ":Instantiating");
	else if (_grade < HIGHEST)
		throw GradeTooLowException(_name, ":Instantiating");
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	grade = src.grade;
}

Bureaucrat Bureaucrat::operator = (const Bureaucrat &src)
{
	this->grade = src.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout<<"Bureaucrat <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

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

void Bureaucrat::signForm(const class AForm &_form)
{

	if (_form.getSign() == false)	
	{
		std::cout<<name<<" signed "<<_form.getName()<<".";
		std::cout<<std::endl;
		_form.beSigned(*this);
	}
	else
	{
		std::cout<<name<<" couldn't sign form "<<_form.getName();
		std::cout<<" because: \e[31m"<<this->getReason()<<std::endl;
	}
}

std::ostream& operator << (std::ostream &out, Bureaucrat &src)
{
	out<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	out<<"."<<std::endl;
	return (out);
}

std::string Bureaucrat::getReason(void) 
{
	return (this->reason);
}

void Bureaucrat::setReason(std::string _reason) const
{
	(void)_reason;
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);		
	}
	catch (std::exception &e)
	{
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	//std::cout<<this->getName()<<" executed "<<form.getName()<<std::endl;
}
