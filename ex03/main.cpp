
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("Sergiu", 10);
	try
	{
		RobotomyRequestForm object("Home");
		b1.signForm(object);
		b1.executeForm(object);
		std::cout<<"SignGrade: "<<object.getSignGrade()<<std::endl;
		std::cout<<"ExecGrade: "<<object.getExecGrade()<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	return (0);
}
