
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyForm", 72, 45)
{
	this->target = target;
	this->isSigned = false;
	std::cout<<"AForm <"<<this->AForm::getName();
	std::cout<<"> initialized successfully!"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("RobotomyForm", 72, 45)
{
	this->target = src.getTarget();
	this->isSigned = src.getSign();
}

RobotomyRequestForm RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
	this->target = src.getTarget();
	this->isSigned = src.getSign();	
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout<<"AForm <"<<this->AForm::getName();
	std::cout<<"> destroyed successfully!"<<std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getExecGrade())
	{
		std::cout<<"Brrrrrrrrrrrrrrrrrrrrrrrrrr....!!!!!!"<<std::endl;
		srand(time(NULL));
		if (rand() % 2) {
			std::cout<<this->getTarget();
			std::cout<<" has been robotomized succesfully!"<<std::endl;
		} else {
			std::cout<<this->getTarget();
			std::cout<<" has not been robotomized succesfully!"<<std::endl;
		}
	}
	else 
		throw AForm::GradeTooLowException(this->getName(), ": Executing!");
}
