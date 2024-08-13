
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

//ShrubberyCreationForm: Required grades: sign 145, exec 137
//RobotomyRequestForm: Required grades: sign 72, exec 45
//PresidentialPardonForm: Required grades: sign 25, exec 5

int main(void)
{
	Bureaucrat b1("Sergiu", 150);
	try
	{
		RobotomyRequestForm RForm("RobotomyForm");
		PresidentialPardonForm PForm("PresidentialForm");
		ShrubberyCreationForm SForm("ShrubberyForm");

		b1.signForm(SForm);
		b1.executeForm(SForm);
		b1.signForm(PForm);
		b1.executeForm(PForm);
		b1.signForm(RForm);
		b1.executeForm(RForm);
	}
	catch (std::exception &e)
	{
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	return (0);
}
