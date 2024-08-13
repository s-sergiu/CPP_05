
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("Sergiu", 145);
	try
	{
		RobotomyRequestForm RForm("RobotomyForm");
		PresidentialPardonForm PForm("PresidentialForm");
		ShrubberyCreationForm SForm("ShrubberyForm");
		b1.signForm(SForm);
		b1.executeForm(SForm);
		std::cout<<"SignGrade: "<<PForm.getSignGrade()<<std::endl;
		std::cout<<"ExecGrade: "<<PForm.getExecGrade()<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	return (0);
}
