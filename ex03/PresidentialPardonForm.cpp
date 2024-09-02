
#include "PresidentialPardonForm.hpp"

// Constructor class
// ------------------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialForm", 25, 5)
{
	this->target = target;
	this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("PresidentialForm", 25, 5)
{
	this->target = src.getTarget();
	this->isSigned = src.getSign();
}

PresidentialPardonForm PresidentialPardonForm::operator = (const PresidentialPardonForm &src)
{
	this->target = src.getTarget();
	this->isSigned = src.getSign();	
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

// Class functions 
// ------------------------------------------------------------------------

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getExecGrade()) {
		std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox.";
		std::cout<<std::endl;
	} else {
		throw AForm::GradeTooLowException(this->getName(), ": Executing!");
	}
}
