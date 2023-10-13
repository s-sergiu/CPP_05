
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyForm", 72, 45)
{
	this->target = target;
	this->isSigned = false;
	std::cout<<"AForm <"<<name;
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
	std::cout<<"AForm <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	//check if the form is signed and grade is high enough;
	srand(time(NULL));
	std::cout<<"Executor's grade: "<<executor.getGrade()<<std::endl;
	std::cout<<"Form's grade: "<<this->getExecGrade()<<std::endl;
	if (this->getSign() == true && executor.getGrade() <= this->getExecGrade())
	{
		std::cout<<"Brrrrrrrrrrrrrrrrrrrrrrrrrr....!!!!!!"<<std::endl;
		if (rand() % 2)
			std::cout<<this->getTarget()<<" has been robotomized succesfully!"<<std::endl;
		else
			std::cout<<this->getTarget()<<" has not been robotomized succesfully!"<<std::endl;
	}
	(void)executor;	
}
