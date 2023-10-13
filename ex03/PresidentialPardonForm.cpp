
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialForm", 25, 5)
{
	this->target = target;
	this->isSigned = false;
	std::cout<<"AForm <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
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
	std::cout<<"AForm <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
	(void)executor;	
}
